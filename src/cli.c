#include <glib.h>

#include "cli.h"

void
get_arguments(
	int *argc,
	char ***argv,
	int *width,
	int *height,
	double *x_mid,
	double *y_mid,
	double *zoom,
	long *iterations
)
{

	// Construct option entries
	GOptionEntry entries[] = {

		// Structure of an option entry
		/*
		{
			const(char)* longName,
			char shortName,
			int flags,
			GOptionArg arg,
			void* argData;
			const(char)* description,
			const(char)* argDescription
		}
		*/

		{
			"width",
			'w',
			0,
			G_OPTION_ARG_INT,
			width,
			"The width of the output image in pixels",
			"600"
		},
		{
			"height",
			'h',
			0,
			G_OPTION_ARG_INT,
			height,
			"The height of the output image in pixels",
			"400"
		},
		{
			"x_mid",
			'x',
			0,
			G_OPTION_ARG_DOUBLE,
			x_mid,
			"The x part of the coordinate in the middle of the image",
			"0.0"
		},
		{
			"y_mid",
			'y',
			0,
			G_OPTION_ARG_DOUBLE,
			y_mid,
			"The y part of the coordinate in the middle of the image",
			"0.0"
		},
		{
			"zoom",
			'z',
			0,
			G_OPTION_ARG_DOUBLE,
			zoom,
			"The zoom factor for the image",
			"1.0"
		},
		{
			"iterations",
			'i',
			0,
			G_OPTION_ARG_INT,
			iterations,
			"The number of maximum iterations to use during image generation",
			"100"
		},
/*
		{
			"output",
			'o',
			16,			// Flag for filename
			G_OPTION_ARG_FILENAME,	// Type: gchar*
			"The name of the output file"
			"file.png"
		},
*/
		{ NULL }
	};

	GError *error = NULL;
	GOptionContext *context;
	
	context = g_option_context_new("- create mandelbrot images");
	g_option_context_add_main_entries(context, entries, NULL);

	if(!g_option_context_parse(context, argc, argv, &error))
	{
		g_print("Option parsing failed: %s\n", error->message);
		exit(1);
	} 

}
