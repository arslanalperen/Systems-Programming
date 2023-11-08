/**
 *
 * Illustrates argument passing in C
 *
 * Compile: Using Linux and gcc
 * 	    gcc -g -Wall -o arg_example1 arg_example1.c
 * Run:     ./arg_example1
 */

#include <stdio.h>

void pass_by_value(int x, int y, int z);

int main(void)
{
	int x, y, z;

	printf("Enter three ints (ex: 8 4 1)\n");
	scanf("%d%d%d", &x, &y, &z);

	printf("In main, x = %d, y = %d, z = %d\n", x, y ,z);
	pass_by_value(x, y, z);

	/* Last print statement. Will the output change? */
	printf("In main, x = %d, y = %d, z = %d\n", x, y, z);

	return 0;
}

void pass_by_value(int x, int y, int z)
{
	printf("In pass_by_value, x = %d, y = %d, z = %d\n", x, y, z);
	/* Let's manipulate these variables here: */
	x = 2 + x;
	y = y - 3;
	z = 7 + z;
	/* Print out the changes: */
	printf("In pass_by_value, x = %d, y = %d, z = %d\n", x, y, z);
}

