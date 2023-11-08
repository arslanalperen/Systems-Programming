/**
 * flush.c
 *
 * Demonstrates flushing the stdout buffer in C
 *
 * Things to try:
 * - Time this program (`time ./flush`)
 * - Time the program again without doing the fflush. Is it faster?
 * - Disable the fflush, segfault the program midway. What prints?
 *
 * Compile: gcc -g -Wall -o flush flush.c
 * Run    : ./flush
 */

#include <stdio.h>

int main()
{
	for (int i = 0; i < 1000000; ++i)
	{
		printf("%d ", i);

		/* We'll flush the output here.
		 * This ensures that everything has been printed to the terminal before continuing
		 * Useful for debugging
		 */
		fflush(stdout);
	}

	return 0;
}
