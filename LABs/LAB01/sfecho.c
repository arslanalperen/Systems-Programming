/**
 * sfecho.c
 *
 */

#include <stdio.h>
#include <string.h>

void strremove(char *str, const char *sub);

int main(int argc, char *argv[]) {
    int newLineArg = 0;
    char *last_arg = argv[argc - 1];

    if (strstr(last_arg, "\\c") != NULL) {
        newLineArg = 1;
        strremove(last_arg, "\\c");
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            newLineArg = 1;
        } else {
            printf("%s", argv[i]);
            if (i < argc - 1) {
                printf(" ");
            }
        }
    }

    if (!newLineArg) {
        printf("\n");
    }

    return 0;
}

void strremove(char *str, const char *sub) {
    size_t len = strlen(sub);
    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
}

