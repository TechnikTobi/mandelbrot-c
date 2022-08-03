#include <stdio.h>
#include <glib.h>

#include "mandelbrot_iteration_checker.h"

int
main(
	int argc,
	char** argv
)
{
	
	static gint repeats = 2;
	static gint max_size = 8;
	static gboolean verbose = TRUE;
	static gboolean beep = TRUE;
	static gboolean randomize = FALSE;

	static GOptionEntry entries[] = {
		{
			"repeats",
			'r',
			0,
			G_OPTION_ARG_INT,
			&repeats,
			"Average over N repetitions",
			"N"
		},
	};

	GError *error = NULL;
	GOptionContext *context;

	context = g_option_context_new("- test tree model performance");
	g_option_context_add_main_entries(context, entries, "tobi-test-text");
	// g_option_context_add_group(context, gtk_get_option_group(TRUE));

	if(!g_option_context_parse(context, &argc, &argv, &error))
	{
		g_print("option parsing failed: %s\n", error->message);
		exit(1);
	}
	



	long test = mandelbrot_iteration_checker(0, 0, 0);

	printf("Mandelbrot!\n");
	printf("%ld", test);

	return 0;
}
