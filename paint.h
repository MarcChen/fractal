#ifndef PAINT_H
#define PAINT_H

/** Create a canvas to paint on */
unsigned char* create_pixels(int width, int height);

/** Destroy the canvas and free its memory.

    Any further use of the canvas may result in
    catastrophic failure. */
void destroy_pixels(unsigned char* pixels);

/** Color the pixel at position (x,y)
    in color (r,g,b) of image with width
    and height, pointed to by pixels.
    */
void color_pixel(int x,int y, unsigned char r, unsigned char g, unsigned char b, int width, int height, unsigned char* pixels);

/** Get the color (r,g,b) of the pixel at position (x,y)
    of image with width and height, pointed to by pixels.
*/
void get_pixel_color(int x,int y, unsigned char* r, unsigned char* g, unsigned char* b, int width, int height, unsigned char* pixels);

/** Write pixels to BMP file */
int save_BMP(char* filename, int width, int height, unsigned char* pixels);

#endif 
