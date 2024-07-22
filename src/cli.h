#ifndef MANDELBROT_CLI_H
#define MANDELBROT_CLI_H

void
get_arguments (
    int    *argc,
    char ***argv,
    int    *width,
    int    *height,
    double *x_mid,
    double *y_mid,
    double *zoom,
    long   *iterations,
    char  **output_file_name
);

#endif
