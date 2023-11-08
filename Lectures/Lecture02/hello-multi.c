/**
 *
 * Greets the world (multiple times)
 *
 * Input: None
 * Output: Several copies of 'Hello World'
 *
 * Compile: Using Linux and gcc
 * gcc -g -Wall hello-multi.c -o hello-multi
 * Run: ./hello-multi
 */

#include <stdio.h>

void say_hello(int time);

int main(int argc, char *argv[])
{
	say_hello(6);
	return 0;
}

void say_hello(int times)
{
	int i;
	for (i = 1; i <= times; ++i){
		printf("Hello, World! (#%d)\n", i);
	}
}
