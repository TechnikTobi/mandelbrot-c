#ifndef MANDELBROT_CLI_H
#define MANDELBROT_CLI_H

void
get_arguments(
	int argc,
	char **argv,
	int *width,
	int *height,
	double *zoom,
	long *iterations
);

#endif
