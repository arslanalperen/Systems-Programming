/**
 * @file hello-multi.c
 * 
 * @date 2021-10-03
 * @author Alperen Arslan (arslanalperen)
 * @version 1.0
 * @bug No known bugs.
 * 
 * @brief Greets the world (multiple times).
 * 
 * Input: None
 * 
 * Output: Several copies of 'Hello World'
 * 
 * Compile: Using Linux and gcc
 * 
 * gcc -g -Wall hello-multi.c -o hello-multi
 * 
 * Run: ./hello-multi
 * 
 * Notes: -g flag enables debugging information. -Wall enables all warnings.
 */

#include <stdio.h>

/**
 * @brief Prints 'Hello, World!' to the screen a given number of times.
 * 
 * @param time Number of times to print 'Hello, World!'
 * @return void
 */
void say_hello(int time);

/**
 * @brief Kernel entry point.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return int Exit status
 */
int main(int argc, char *argv[]) {
	say_hello(6);
	return 0;
}

void say_hello(int times) {
	for (int i = 1; i <= times; ++i)
		printf("Hello, World! (#%d)\n", i);
}