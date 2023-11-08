/**
 * getopt.c
 *
 * Demonstrates using the getopt() function to parse command line options
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main (int argc, char *argv[])
{
	char *str_option = "default string";
	bool a_flag, b_flag, s_flag = false;

	int c;
	opterr = 0;
	
	while ((c = getopt(argc, argv, "abs:")) != -1)
		switch (c)
		{
			case 'a':
				a_flag = true;
				break;
			case 'b':
				b_flag = true;
				break;
			case 's':
				s_flag = true;
				str_option = optarg;
				break;
			case '?':
				if (optopt == 's')
					fprintf(stderr, "Option '-%c' requires an argument.\n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Unknown option '-%c'.\n", optopt);
				else
					fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
				return 1;
			default:
				abort();
		}

	printf("a_flag = %s, b_flag = %s, s_flag = %s\n", a_flag ? "true" : "false", b_flag ? "true" : "false", s_flag ? "true" : "false");

	printf("str_option = %s\n", str_option);

	for (int index = optind; index < argc; index++)
		printf("Non-option argument %s\n", argv[index]);
	
	return 0;
}
