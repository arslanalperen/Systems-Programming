/**
 * print_addresses.c
 *
 * Illustrates argument passing in C with memory addresses.
 *
 * Compile: Using Linux and gcc
 * 	    gcc -g -Wall -o print_addresses print_addresses.c
 * Run:     ./print_addresses
 */

#include <stdio.h>

void by_value(int number);
void by_reference(int *number);

int main(int argc, char *argv[])
{
	int num1;

	printf("Enter an integer: ");
	scanf("%d", &num1);

	printf("[ 1 ] Number = [ %d ], and its address is [ %p ]\n", num1, &num1);

	by_value(num1);
	by_reference(&num1);

	int num2 = num1;

	printf("[ 2 ] Number = [ %d ], and its address is [ %p ]\n", num2, &num2);
	by_value(num2);
	by_reference(&num2);

	return 0;
}

/* Here, we are passing in a *value*. In other words, our 'actual args'
 * contain the integer itself. Because of this a copy is being made in memory,
 * and will have a different memory address.
 */
void by_value(int number)
{
	printf("[VAL] number = [ %d ], and its address is [ %p ]\n", number, &number);
}

/* Here, we are passing in a *pointer*, something that refers to a memory address.
 * No copy of value takes place;
 * note how the address will be the same as the address of what was passed in.
 */
void by_reference(int *number)
{
	printf("[REF] Number = [ %d ], and its address is [ %p ]\n", *number, number);
}
