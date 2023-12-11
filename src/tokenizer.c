#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int is_space_char(char c) {
    return (c == ' ' || c == '\t') && c != '\0';
}

int is_non_space_char(char c) {
    return !(c == ' ' || c == '\t') && c != '\0';
}

char *token_start(char *str) {
    int indx = 0;
    while (is_space_char(str[indx])) {
        indx++;
    }
    return str + indx;
}

char *token_terminator(char *str) {
    int indx = 0;
    while (is_non_space_char(str[indx])) {
        indx++;
    }
    return str + indx;
}

int count_tokens(char *str) {
    int tokenCount = 0;
    char *holder = str;
    while (*holder) {
        if (is_non_space_char(*holder)) {
            tokenCount++;
        }
        holder = token_start(token_terminator(holder));
    }
    return tokenCount;
}

char *copy_str(char *inStr, short len) {
    char *inStrCopy = malloc((len + 1) * sizeof(char));
    if (inStrCopy == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; i++) {
        inStrCopy[i] = inStr[i];
    }
    inStrCopy[len] = '\0';
    return inStrCopy;
}

char **tokenize(char *str) {
    int length, wordCount = count_tokens(str);
    char **tokens = malloc((wordCount + 1) * sizeof(char *));
    if (tokens == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    char *p = str;
    for (int i = 0; i < wordCount; i++) {
        p = token_start(p);
        length = token_terminator(p) - p;
        tokens[i] = copy_str(p, length);
        p = token_terminator(p);
    }
    tokens[wordCount] = NULL;
    return tokens;
}

// Rest of the code remains unchanged

