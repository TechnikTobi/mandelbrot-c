#include <stdlib.h>

#include "mandelbrot_iteration_checker.h"

#define DEFAULT_SPAN 2.0

long*
generate_raw_data(
	int width,
	int height,
	double x_mid,
	double y_mid,
	double zoom,
	long iterations
)
{

	// Calculate necessary delimiters of image
	double x_span, y_span, ppi;
	x_span = DEFAULT_SPAN / zoom; 
	ppi = x_span / width;
	y_span = ppi * height;

	double x_start, y_end;
	x_start = x_mid - x_span/2.0;
	y_end = y_mid + y_span/2.0;

	// Get memory to write to
	long* raw_data = (long*) malloc(width * height * sizeof(long));

	// Generate data
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			raw_data[y*width + x] = mandelbrot_iteration_checker(
				x_start + ppi * x,
				y_end - ppi * y,
				iterations
			);
		}
	}
	
	return raw_data;
}
