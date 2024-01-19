#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "paint.h"

unsigned char* create_pixels(int width, int height) {
  // Allocate memory
  // unsigned char* pixels = malloc(width*height*3*sizeof(unsigned char));
  unsigned char* pixels = calloc(width*height*3,sizeof(unsigned char));
  return pixels;
}

void destroy_pixels(unsigned char* pixels) {
  free(pixels);
}

void color_pixel(int x,int y, unsigned char r, unsigned char g, unsigned char b, int width, int height, unsigned char* pixels) {
  // don't paint outside image
  if (x<0) {
    x = 0;
  } else if (x>=width) {
    x = width-1;
  }
  if (y<0) {
    y = 0;
  } else if (y>=height) {
    y = height-1;
  }
  // Note: color order in BMP is BGR
  pixels[3*(y*width+x)] = b;
  pixels[3*(y*width+x)+1] = g;
  pixels[3*(y*width+x)+2] = r;
}

void get_pixel_color(int x,int y, unsigned char* r, unsigned char* g, unsigned char* b, int width, int height, unsigned char* pixels) {
  // don't paint outside image
  if (x<0) {
    x = 0;
  } else if (x>=width) {
    x = width-1;
  }
  if (y<0) {
    y = 0;
  } else if (y>=height) {
    y = height-1;
  }
  // Note: color order in BMP is BGR
  *b = pixels[3*(y*width+x)];
  *g = pixels[3*(y*width+x)+1];
  *r = pixels[3*(y*width+x)+2];
}

//supply an array of pixels[3*height*width] 
// adapted from https://pastebin.com/qCRHiPEZ
int save_BMP(char* filename, int width, int height, unsigned char* pixels) {
    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);  
    static unsigned char header[54] = {66,77,0,0,0,0,0,0,0,0,54,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,1,0,24}; //rest is zeroes
    unsigned int pixelBytesPerRow = width*3;
    unsigned int paddingBytesPerRow = (4-(pixelBytesPerRow%4))%4;
    unsigned int* sizeOfFileEntry = (unsigned int*) &header[2];
    *sizeOfFileEntry = 54 + (pixelBytesPerRow+paddingBytesPerRow)*height;  
    unsigned int* widthEntry = (unsigned int*) &header[18];    
    *widthEntry = width;
    unsigned int* heightEntry = (unsigned int*) &header[22];    
    *heightEntry = height;    
    write(fd, header, 54);
    static unsigned char zeroes[3] = {0,0,0}; //for padding    
    for (int row = 0; row < height; row++) {
        // Note: BMP rows are written from the bottom up (unless height is negative)
        write(fd,pixels+3*(height-1-row)*width,pixelBytesPerRow);
        write(fd,zeroes,paddingBytesPerRow);
    }
    close(fd);
    return 0;
}

