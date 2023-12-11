#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

#define MAXCHARS 100
List *history;
char **tokens;
int globalid;      // keep track of current history id
int tokenlength;
char *specificHist;

int user_options(char *str) {
    char *ptr = str;
    int option;

    if (strncmp(ptr, "e", 1) == 0 || strncmp(ptr, "E", 1) == 0) {
        return 0;
    } else if (strncmp(ptr, "h", 1) == 0 || strncmp(ptr, "H", 1) == 0) {
        printf("To see overall history enter \"o\", to see specific history enter \"!\" followed by a number. To return to the main menu enter \"m\".\n$-");
        fgets(ptr, MAXCHARS, stdin);

        while (ptr[0] != 'm') {
            switch (ptr[0]) {
                case 'o':
                case 'O':
                    printf("---You chose overall history---\n");
                    if (!history->root) {
                        printf("List is empty, please enter some input\n$-");
                        fgets(ptr, MAXCHARS, stdin);
                        printf("---Input successfully added to history---\n\n");
                        add_history(history, ptr);
                    } else {
                        print_history(history);
                    }
                    break;
                case '!':
                    if (!history->root) {
                        printf("List is empty, please enter some input\n$-");
                        fgets(ptr, MAXCHARS, stdin);
                        printf("---Input successfully added to history---\n\n");
                        add_history(history, ptr);
                    } else {
                        printf("Enter a number for specific history:\n");
                        printf("Current history id: %d\n$-", globalid);
                        fgets(ptr, MAXCHARS, stdin);
                        finalized_options(ptr, token_length(ptr));

                        while (atoi(ptr) <= 0 || atoi(ptr) > globalid) {
                            printf("Entered history id %s not found. Please enter a valid history id:\n$-", str);
                            fgets(ptr, MAXCHARS, stdin);
                            finalized_options(ptr, token_length(ptr));
                        }

                        printf("---Tokenizing string at specific history place: %d---.\n", atoi(str));
                        specificHist = get_history(history, atoi(str));
                        tokens = tokenize(specificHist);
                        print_tokens(tokens);
                        free_tokens(tokens);
                    }
                    break;
                default:
                    printf("Please enter a valid input. ");
                    break;
            }
            printf("For overall history enter \"o\". To see specific history enter \"!\". To return to the main menu enter \"m\"\n$-");
            fgets(ptr, MAXCHARS, stdin);
        }
        return 2;
    } else {
        return 1;
    }
}

int main() {
    char input[MAXCHARS], *ptr;
    int menuOption;
    history = init_history();

    printf("Welcome! Please enter some input. Enter \"e\" to exit or \"h\" to see history.\n");
    while (1) {
        printf("$-");
        fgets(input, MAXCHARS, stdin);
        ptr = input;
        ptr = token_start(ptr);
        finalized_options(ptr, tokenlength);

        menuOption = user_options(ptr);
        switch (menuOption) {
            case 0:
                printf("Goodbye\n");
                free_history(history);
                return 0;
            case 1:
                add_history(history, ptr);
                printf("---Input successfully added to history---\n\n");
                break;
            case 2:
                printf("Welcome! Please enter some input. Enter \"e\" to exit or \"h\" to see history\n");
                break;
            default:
                break;
        }
    }
    return 0;
}
