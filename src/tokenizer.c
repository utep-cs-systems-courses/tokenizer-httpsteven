#include <stdio.h>

#include <stdlib.h>

#include "history.h"

#include "tokenizer.h"



// Checks if the character is a space or tab

int space_char(char c) {

  int isSpace = ((c == ' ' || c == '\t') && c != '\0');

  return isSpace;

}



// Checks if the character is not a space or tab

int non_space_char(char c) {

  int isNotSpace = (!(c == ' ' || c == '\t') && c != '\0');

  return isNotSpace;

}



// Finds the starting point of a token by skipping extra spaces or tabs

char *token_start(char *str) {

  int index = 0;

  while (space_char(str[index]))

    index++;

  return str + index;

}



// Finds the end of a token by moving to the last character that is not a space or tab

char *token_terminator(char *str) {

  int index = 0;

  while (non_space_char(str[index]))

    ++index;

  return str + index;

}



// Counts the number of tokens in a string

int count_tokens(char *str) {

  int tokenCount = 0;

  char *holder = str;

  while (*holder) {

    if (non_space_char(*holder))

      tokenCount++;

    holder = token_start(token_terminator(holder));

  }

  return tokenCount;

}



// Copies a string of specified length

char *copy_str(char *inStr, short len) {

  char *inStrCopy = malloc((len + 1) * sizeof(char));

  int i;

  for (i = 0; i < len; i++) {

    inStrCopy[i] = inStr[i];

  }

  inStrCopy[i] = '\0';

  return inStrCopy;

}



// Splits a string into tokens and returns an array of tokenized strings

char **tokenize(char *str) {

  int i, length, wordCount = count_tokens(str);

  char **tokens = malloc((wordCount + 1) * sizeof(char*));

  char *p = str;

  i = 0;

  for (; i < wordCount; i++) {

    p = token_start(p);

    length = token_terminator(p) - p;

    tokens[i] = copy_str(p, length);

    p = token_terminator(p);

  }

  tokens[i] = NULL;

  return tokens;

}



// Prints the tokens contained in the given array

void print_tokens(char **tokens) {

  for (int i = 0; tokens[i]; i++)

    printf("Token[%d]: %s\n", i + 1, tokens[i]);

}



// Frees memory allocated for the token strings and the array

void free_tokens(char **tokens) {

  int i = 0;

  while (tokens[i]) {

    free(tokens[i]);

    i++;

  }

  free(tokens);

}



// Adjusts user options by removing newlines for a user option or when a history ID is not found

void finalized_options(char *str, int length) {

  if (str[1] == '\n')

    str[1] = '\0'; // Removes newline for a user option

  if (str[length - 1] == '\n')

    str[length - 1] = '\0'; // Removes newline when a history ID is not found

}



// Calculates the length of a string

int token_length(char *str) {

  int i = 0;

  char *holder = str;

  while (holder[i] != '\0') {

    i++;

  }

  return i;

}

