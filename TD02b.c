#include "paint.c"
#include <math.h>
#include <stdio.h>

int compter_iterations(double x, double y, int max_iter) {
  double a = 0;
  double b = 0;
  double c = 0;
  int k = 0;

  while (a * a + b * b <= 4 && k < max_iter) {
    c = a * b;
    a = a * a - b * b + x;
    b = 2 * c + y;
    k = k + 1;
  }
  return k;
}

double transfo_y(int j, double width, double height, double x_left,
                 double y_top, double x_width) {
  double y_height = x_width * height / width;
  double a = -(y_height / (height - 1));
  double b = y_top;
  return a * j + b;
}

double transfo_x(int i, double width, double height, double x_left,
                 double y_top, double x_width) {
  double a = x_width / (width - 1);
  double b = x_left;
  return a * i + b;
}

int main() {

  double width = 600;
  double height = 400;
  double x_left = -2;
  double y_top = 1;
  double x_width = 3;
  int max_iter = 100;
  double dx = 0.4;
  double dy = 0.93;
  double g = -1.57;


  unsigned char *pixels = create_pixels(width, height);

  for (int i = 0; i <= width; ++i) {
    for (int j = 0; j <= height; ++j) {
      double x = transfo_x(i, width, height, x_left, y_top, x_width);
      double y = transfo_y(j, width, height, x_left, y_top, x_width);
      x = x + dx;
      y = y + dy;
      float xr = x * cos(g) + y * sin(g);
      y = -x * sin(g) + y * cos(g);
      x = xr;
      int iteration = compter_iterations(x, y, max_iter);
      unsigned char r, g, b;
      if (iteration == max_iter) {
        r = floor(cos(i - j) * 100);
        g = 200;
        b = floor(cos(j - i) * 100);
      } else {
        r = floor(10 * exp(150 - r));
        g = floor(sin(255 * iteration / max_iter));
        b = 0;
      }
      color_pixel(i, j, r, g, b, width, height, pixels);
    }
  }

  save_BMP("fractal.bmp", width, height, pixels);
  destroy_pixels(pixels);
  return 0;
} 