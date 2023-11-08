/**
 * arg_passing.c
 *
 * Demonstrates passing arguments by value and also simulates passing by reference using pointers.
 *
 * Compile: Using Linux and gcc
 * 	    gcc -g -Wall -o arg_passing arg_passing.c
 * Run:     ./arg_passing
 *
 */

#include <stdio.h>

void our_func1(int x);
void our_func2(int *x);

int main(void)
{
	int a = 9;
	our_func1(a);
	printf("a is: %d\n", a);
	our_func2(&a);
	printf("a is: %d\n", a);

	return 0;
}

void our_func1(int x)
{
	x = 24;
	printf("The address of x is: %p\n", &x);
}

void our_func2(int *x)
{
	*x = 24;
	printf("The address of x is: %p\n", x);
}
