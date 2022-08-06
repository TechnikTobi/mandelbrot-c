#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <limits.h>

#include "color_map.h"

void
write_png(
	int width,
	int height,
	char* filename,
	unsigned char* rgb_data
)
{
	// Pointers to different data structures
	FILE *file_pointer;
	png_structp png_pointer;
	png_infop info_pointer;
	png_bytep row_pointer;

	file_pointer = fopen(filename, "wb");
	png_pointer = png_create_write_struct(
		PNG_LIBPNG_VER_STRING,
		NULL,
		NULL,
		NULL
	);
	info_pointer = png_create_info_struct(png_pointer);
	
	png_init_io(png_pointer, file_pointer);
	png_set_IHDR(
		png_pointer, 
		info_pointer,
		width,
		height,
		CHAR_BIT,
		PNG_COLOR_TYPE_RGB,
		PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_BASE,
		PNG_FILTER_TYPE_BASE
	);
	png_write_info(png_pointer, info_pointer);
	row_pointer = (png_bytep) malloc(width * COLOR_CHANNELS * sizeof(unsigned char));

	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i < width; i++)
		{
			for(int c = 0; c < COLOR_CHANNELS; c++)
			{
				int row_pointer_address = i*COLOR_CHANNELS + c;
				int rgb_data_address = (j*width + i)*COLOR_CHANNELS + c;
				row_pointer[row_pointer_address] = rgb_data[rgb_data_address];
			}
		}
		
		png_write_row(png_pointer, row_pointer);
	}

	png_write_end(png_pointer, NULL);
	fclose(file_pointer);
}
