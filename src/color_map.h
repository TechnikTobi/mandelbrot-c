#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#define COLOR_CHANNELS 3

typedef enum
{
	DEFAULT,
	BLUE,
	BW
}e_color_mode;

unsigned char*
map_raw_to_rgb(
	int width,
	int height,
	long* raw_data,
	long iterations,
	e_color_mode mode
);

void
color_mode_blue(
	long* raw_data,
	unsigned long raw_data_size,
	long iterations,
	unsigned char* rgb_data
);

#endif
