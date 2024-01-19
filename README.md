# Fractal Generator README

## Overview
This project is a simple fractal generator implemented in C. It generates and colors fractal images based on the Mandelbrot set. The generated images can be saved as BMP files. This README file provides information on how to use and modify the code.

## Usage
To use this fractal generator, follow these steps:

1. Include the "paint.c" file in your project.
2. Include the necessary libraries: `math.h` and `stdio.h`.

3. Define the parameters for your fractal image in the `main` function:
   - `width`: Width of the image in pixels.
   - `height`: Height of the image in pixels.
   - `x_left`: Leftmost x-coordinate of the fractal region.
   - `y_top`: Topmost y-coordinate of the fractal region.
   - `x_width`: Width of the fractal region.
   - `max_iter`: Maximum number of iterations to determine the color of each pixel.
   - `dx`: Horizontal translation applied to the fractal.
   - `dy`: Vertical translation applied to the fractal.
   - `g`: Rotation angle applied to the fractal.

4. Create an array of unsigned characters to store the pixel data using the `create_pixels` function.

5. Loop through each pixel in the image, calculate the corresponding coordinates in the fractal region using `transfo_x` and `transfo_y`, and apply translations and rotations as needed.

6. Calculate the number of iterations required to determine the color of the pixel using the `compter_iterations` function.

7. Based on the iteration count, assign colors to the pixel using custom logic.

8. Use the `color_pixel` function to set the pixel's color in the pixel array.

9. After processing all pixels, save the generated image as a BMP file using the `save_BMP` function.

10. Clean up by destroying the pixel array using the `destroy_pixels` function.

## Modifying Colors
You can modify the colors of the generated image by adjusting the color logic within the loop in the `main` function. There is a commented-out section labeled "Modification of Colors" (`Q8`) that you can uncomment and modify as needed to achieve your desired color scheme.

## Adding Translation
To add translation to the fractal, you can adjust the values of `dx` and `dy` in the `main` function (`Q9`). These values control the horizontal and vertical translations applied to the fractal.

## Adding Rotation
You can add rotation to the fractal by adjusting the value of `g` in the `main` function (`Q9`). This value controls the rotation angle applied to the fractal.

## Important Note
When applying translation and rotation, it's recommended to use intermediate variables (`xr`, `y`) to ensure the transformations are correctly applied. Refer to the provided code (`CODE FINAL`) for an example of how to apply translation and rotation.

Feel free to customize this code and experiment with different parameters to create unique fractal images. Enjoy exploring the world of fractals!
