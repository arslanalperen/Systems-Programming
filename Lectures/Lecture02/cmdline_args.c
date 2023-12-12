/**
 * @file cmdline_args.c
 * 
 * @date 2021-10-03
 * @author Alperen Arslan (arslanalperen)
 * @version 1.0
 * @bug No known bugs.
 * 
 * @brief Viewing command line arguments.
 * 
 * Input: Command line arguments
 * 
 * Output: Command line arguments
 * 
 * Compile: Using Linux and gcc
 * 
 * gcc -g -Wall cmdline_args.c -o cmdline_args
 * 
 * Run: ./cmdline_args arg1 arg2 arg3 ...
 * 
 * Notes: -g flag enables debugging information. -Wall enables all warnings.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Kernel entry point.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return int Exit status
 */
int main(int argc, char *argv[]) {
	/**
	 * Loop through the command line arguments, printing each one on a seperate line.
	 */
	int i;
	for (i = 0; i < argc; ++i) {
		printf("[%s]\n", argv[i]);
	}

	/**
	 * Returning an exit code other than 0.
	 * We can use EXIT_FAILURE to indicate a problem, or provide our own exit code. 
	 * To view the exit code, use:
	 * echo $?
	 * In your shell.
	 */
	return 3;
}