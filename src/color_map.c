#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "color_map.h"

#define COLOR_CHANNELS 3

unsigned char*
map_raw_to_rgb(
	int width,
	int height,
	long* raw_data,
	long iterations,
	e_color_mode mode
){

	unsigned long raw_data_size = width * height;
	unsigned long rgb_data_bytes = raw_data_size * sizeof(unsigned char) * COLOR_CHANNELS;
	unsigned char* rgb_data = (unsigned char*) malloc(rgb_data_bytes);

	switch(mode)
	{
		case BLUE:
			color_mode_blue(raw_data, raw_data_size, iterations, rgb_data);
			printf("Blue\n");
			break;
		default:
			printf("Default\n");
	};

	return rgb_data;
}

void
color_mode_blue(
	long* raw_data,
	unsigned long raw_data_size,
	long iterations,
	unsigned char* rgb_data
)
{
	for(unsigned long i = 0; i < raw_data_size; i++)
	{
		int transformed_value = round(
			(((long double)raw_data[i]) / ((long double)iterations)) * ((long double)765)
		);

		if(transformed_value < 255)
		{
			rgb_data[COLOR_CHANNELS*i + 0] = 0;
			rgb_data[COLOR_CHANNELS*i + 1] = 0;
			rgb_data[COLOR_CHANNELS*i + 2] = transformed_value;
		}
		else if(transformed_value < 511)
		{
			rgb_data[COLOR_CHANNELS*i + 0] = 0;
			rgb_data[COLOR_CHANNELS*i + 1] = transformed_value - 255;
			rgb_data[COLOR_CHANNELS*i + 2] = 255;
		}
		else
		{
			rgb_data[COLOR_CHANNELS*i + 0] = transformed_value - 510;
			rgb_data[COLOR_CHANNELS*i + 1] = 255;
			rgb_data[COLOR_CHANNELS*i + 2] = 255;
		}
	}		
}	
