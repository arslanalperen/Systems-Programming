/**
 * @file hello.c
 * 
 * @date 2021-10-03
 * @author Alperen Arslan (arslanalperen)
 * @version 1.0
 * @bug No known bugs.
 * 
 * @brief Greets the world.
 * 
 * Known as "the first C program," from K&R. Greets the world.
 * 
 * Input: None
 * Output: "Hello, World!"
 * 
 * Compile: Using Linux and gcc
 * gcc -E hello.c > hello.pre (Only perform the preproccesing step)
 * gcc -S hello.c (Only perform the assembly step)
 * gcc -c hello.c (Only perform the compilation step)
 * hexdump -C hello.o (View the object file)
 * gcc -g -Wall hello.c -o hello (Perform all steps)
 * 
 * Run: ./hello
 * 
 * Notes: -g flag enables debugging information. -Wall enables all warnings.
 */

#include <stdio.h>

/**
 * @brief Kernel entry point.
 * 
 * @return int Exit status
 */
int main(void) {
    printf("Hello, World!\n");

    return 0;
}