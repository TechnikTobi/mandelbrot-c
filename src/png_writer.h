#ifndef PNG_WRITER_H
#define PNG_WRITER_H

void
write_png (
    int            width,
    int            height,
    char          *filename,
    unsigned char *rgb_data
);

#endif
