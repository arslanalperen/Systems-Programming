/**
 * cmdline_args.c
 *
 * Viewing command line arguments.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* Loop through the command line arguments, printing each one on a seperate
	 * line. */
	int i;
	for (i = 0; i < argc; ++i){
		printf("[%s]\n", argv[i]);
	}

	/* Returning an exit code other than 0. We can use EXIT_FAILURE to indicate 
	 * a problem, or provide our own exit code. To view the exit code, use:
	 * echo $?
	 * In your shell.
	 */
	return 3;
}
