/**
 * array_break.c
 *
 * Let's test the limits of going out of bounds in C.
 *
 */

#include <stdio.h>

int main(void)
{
	int arr[10000];

	int i;
	for (i = 0; i < 1000000; ++i)
	{
		arr[i] = i;
		printf("-> %d\n", arr[i]);
	}

	return 0;
}
