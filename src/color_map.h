#ifndef COLOR_MAP_H
#define COLOR_MAP_H

typedef enum
{
	DEFAULT,
	BLUE,
	BW
}e_color_mode;

int*
map_raw_to_rgb(
	int width,
	int height,
	long* raw_data,
	long iterations,
	e_color_mode mode
);


#endif
