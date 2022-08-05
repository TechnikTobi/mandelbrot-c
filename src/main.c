#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "generator.h"
#include "color_map.h"

int
main(
	int argc,
	char** argv
)
{
	
	// Define parameters
	int width = 200;
	int height = 100;
	double x_mid = 0.0;
	double y_mid = 0.0;
	double zoom = 1.0;
	long iterations = 100;

	// Get user input from CLI
	get_arguments(
		&argc, 
		&argv, 
		&width, 
		&height, 
		&x_mid,
		&y_mid,
		&zoom, 
		&iterations
	);

	// Print the values that are going to be used
	printf("Width:      %d\n", width);
	printf("Height:     %d\n", height);
	printf("X-Mid:      %f\n", x_mid);
	printf("Y-Mid:      %f\n", y_mid);
	printf("Zoom:       %f\n", zoom);
	printf("Iterations: %ld\n", iterations);

	// Generate raw fractal data
	long* raw_data = generate_raw_data(
		width,
		height,
		x_mid,
		y_mid,
		zoom,
		iterations
	);

	// CLI output for testing purposes
	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i < width; i++)
		{
			if(raw_data[j*width + i] > iterations/2)
			{
				printf("#");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}

	unsigned char* rgb_data = map_raw_to_rgb(
		width,
		height,
		raw_data,
		iterations,
		(e_color_mode)1
	);

	// Freeing data
	free(raw_data);
	free(rgb_data);

	return 0;
}
