#include <stdio.h>

#include "mandelbrot_iteration_checker.h"

int
main(
	int argc,
	char** argv
)
{

	int test = iteration_checker(0, 0, 0, 0, 0);

	printf("Mandelbrot!\n");
	printf("%d", test);

	return 0;
}
