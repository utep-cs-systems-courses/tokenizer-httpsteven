#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c);

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c);

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str); 

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token);

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str);

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

/* finalizes input by getting rid of the newline from fgets() for user options */
void finalized_options(char *str, int length);

int token_length(char *str);

extern List* history;     // pointer to linked list
extern char **tokens;     // double pointer for all tokens in a string
extern int globalid;       // keep track of the current history id

#endif
