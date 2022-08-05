#include <stdio.h>
#include <stdlib.h>

#include "color_map.h"

int*
map_raw_to_rgb(
	int width,
	int height,
	long* raw_data,
	long iterations,
	e_color_mode mode
){

	int* rgb_data = NULL;


	if(rgb_data == NULL)
	{
		printf("Error during color mapping: Pointer to return data must not be NULL\n");
		exit(1);
	}

	return rgb_data;
}
