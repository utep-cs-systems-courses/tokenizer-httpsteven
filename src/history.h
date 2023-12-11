#ifndef HISTORY_H
#define HISTORY_H

typedef struct s_Item {
    int id;
    char *str;
    struct s_Item *next;
} Item;

typedef struct s_List {
    struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history();

/* Add a history item to the end of the list. */
void add_history(List *list, char *str);

/* Retrieve the string stored in the node where Item->id == id. */
char *get_history(List *list, int id);

/* Print the entire contents of the list. */
void print_history(List *list);

/* Free the history list and the strings it references. */
void free_history(List *list);

/* Copy the input string with a specified length. */
char *copy_str(char *inStr, short len);

/* Global variables. */
extern int globalid;
extern int newline;

#endif