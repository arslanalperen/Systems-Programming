#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define WORDLE_WORD_LENGTH 5

int main (void) {
    FILE *wordList = fopen("/usr/share/dict/words", "r");

    if (wordList == NULL) {
        perror("Failed to open word list!\n");
        return 1;
    } else
        fprintf(stdout, "Word list opened successfully!\n");

    char word[MAX_WORD_LENGTH];
    char target[WORDLE_WORD_LENGTH + 1]; // +1 for null-terminator

    int validWords = 0;
    
    srand(time(NULL));

    while (fgets(word, MAX_WORD_LENGTH, wordList) != NULL) {
        word[strcspn(word, "\r\n")] = '\0';
        
        int isValid = 0;
        
	if (strlen(word) == WORDLE_WORD_LENGTH) {
            isValid = 1;
            for (int i = 0; i < WORDLE_WORD_LENGTH; i++)
                if (!isalpha(word[i])){
                    isValid = 0;
                    break;
                }
        }

        if (isValid == 1) {
            validWords++;
            if (rand() % validWords == 0){
                strncpy(target, word, WORDLE_WORD_LENGTH);
                target[WORDLE_WORD_LENGTH] = '\0'; //Null-terminate the target	    
	    }
	}
    }

    fclose(wordList);

    if (strlen(target) != WORDLE_WORD_LENGTH) {
        printf("Couldn't find a valid word of length %d in the word list", WORDLE_WORD_LENGTH);
        return 2;
    }

    printf("The word is: %s\n", target);

    for (int i = 0; i < 6; i++) {
        char guess[MAX_WORD_LENGTH];
        fprintf(stdout, "Enter your guess: ");
        fscanf(stdin, "%s", guess);

        if (strlen(guess) != WORDLE_WORD_LENGTH) {
            fprintf(stdout, "That is not %d characters you idiot!\n", WORDLE_WORD_LENGTH);
            continue;
        }

        printf("                  ");
        
        for (int j = 0; j < WORDLE_WORD_LENGTH; j++) {
            if (target[j] == guess[j])
                fprintf(stdout,"o");
            else if (strchr(target, guess[j]) != NULL)
                fprintf(stdout, "a");
            else
                fprintf(stdout, "x");
        }

        puts("");

        if (strncmp(target, guess, WORDLE_WORD_LENGTH) == 0) {
            fprintf(stdout, "YOU WINNNNNN!\n");
            break;
        }
    }

    return 0;
}
