#include <stdio.h>

#include "cli.h"
#include "mandelbrot_iteration_checker.h"

int
main(
	int argc,
	char** argv
)
{
	
	int width = 200;
	int height = 100;
	double x_mid = 0.0;
	double y_mid = 0.0;
	double zoom = 1.0;
	long iterations = 100;

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

	printf("%d\n", width);
	printf("%ld\n", iterations);

	long test = mandelbrot_iteration_checker(0, 0, 0);

	printf("%ld\n", test);

	return 0;
}
