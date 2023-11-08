#include <stdio.h>

void awesome_function(int x[]);

int main(void)
{
	int cool_array[4049];
	printf("The memory address of cool_array is: %p\n", cool_array);

	/* This loops checks for array elements that are NOT zero
	 * C does not initialize variables to 0 for us, so it could actually contain other values
	 */
	for (int i = 0; i < 4049; ++i)
	{
		if (cool_array[i] != 0)
			printf("%d\n", cool_array[i]);
	}

	printf("Size of an array is: %zu\n", sizeof(cool_array) / sizeof(int));
	 awesome_function(cool_array);

	return 0;
}

/* Function do not know if it points to a single value or is it the start of an array */

void awesome_function(int x[])
{
	printf("The memory address of x is: %p\n", &x);
	printf("The memory address of x (again) is: %p\n", x);
	//printf("Size of an array is: %zu\n", sizeof(x) / sizeof(int));
}
