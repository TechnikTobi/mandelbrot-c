#include "mandelbrot_iteration_checker.h"

#include <complex.h>

#define SQR_THRESHOLD 4

long
mandelbrot_iteration_checker (
    long double x,
    long double y,
    long        iterations
)
{
    long double complex z = 0.0 + 0.0 * I;
    long double complex c = x + y * I;

    long iteration_counter = 0;

    while (
        creal(z) * creal(z) + cimag(z) * cimag(z) <= SQR_THRESHOLD &&
        iteration_counter < iterations
    )
    {
        z = z * z + c;
        iteration_counter++;
    }

    return iteration_counter;
}
