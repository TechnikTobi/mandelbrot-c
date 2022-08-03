#include <glib.h>

#include "cli.h"

void
get_arguments(
	int argc,
	char **argv,
	int *width,
	int *height,
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
			"W"
		},
		{
			"height",
			'h',
			0,
			G_OPTION_ARG_INT,
			height,
			"The height of the output image in pixels",
			"H"
		},

		{
			"output",
			'o',
			16,			// Flag for filename
			G_OPTION_ARG_FILENAME,	// Type: gchar*
			"The name of the output file"
			"file.png"
		},
	};

	GError *error = NULL;
	GOptionContext *context;
	
	context = g_option_context_new("- create mandelbrot images");
	g_option_context_add_main_entries(context, entries, NULL);

	if(!g_option_context_parse(context, &argc, &argv, &error))
	{
		g_print("Option parsing failed: %s\n", error->message);
		exit(1);
	} 

}
