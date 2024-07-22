#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"
#include "color_map.h"
#include "generator.h"
#include "png_writer.h"

#define MAX_FILENAME 255

int
main (
    int    argc,
    char** argv
)
{
    // Define parameters
    int    width            = 400;
    int    height           = 400;
    double x_mid            = 0.0;
    double y_mid            = 0.0;
    double zoom             = 0.5;
    long   iterations       = 100;
    char*  output_file_name = NULL;

    // Get user input from CLI
    get_arguments(
        &argc,
        &argv,
        &width,
        &height,
        &x_mid,
        &y_mid,
        &zoom,
        &iterations,
        &output_file_name
    );

    // Check if a file name was given. If not, use a default value
    if (output_file_name == NULL)
    {
        output_file_name = (char*)malloc(MAX_FILENAME * sizeof(char));
        strcpy(output_file_name, "image.png");
    }

    // Print the values that are going to be used
    printf("Width:      %d\n", width);
    printf("Height:     %d\n", height);
    printf("X-Mid:      %f\n", x_mid);
    printf("Y-Mid:      %f\n", y_mid);
    printf("Zoom:       %f\n", zoom);
    printf("Iterations: %ld\n", iterations);
    printf("Filename: %s\n", output_file_name);

    // Generate raw fractal data
    long* raw_data = generate_raw_data(
        width,
        height,
        x_mid,
        y_mid,
        zoom,
        iterations
    );

    // Map the raw data to RGB color data
    unsigned char* rgb_data = map_raw_to_rgb(
        width,
        height,
        raw_data,
        iterations,
        (e_color_mode)1
    );

    // Create a PNG file using the RGB data
    write_png(width, height, output_file_name, rgb_data);

    // Freeing the used memory
    free(raw_data);
    free(rgb_data);
    if (output_file_name != NULL) free(output_file_name);

    return 0;
}
