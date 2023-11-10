#include <stdlib.h>

#include <stdio.h>

#include "history.h"

#include "tokenizer.h"



// Initialize a new history list

List* init_history() {

  List *list = malloc(sizeof(List));

  if (list != NULL) {

    list->root = NULL;

  }

  return list;

}



// Add a new item (token) to the history list

void add_history(List *list, char *token) {

  Item *newItem = (Item*) malloc(sizeof(Item));

  if (newItem != NULL) {

    // Copy the token and assign a unique ID

    newItem->str = copy_str(token, token_length(token));

    newItem->id = 1;



    if (list->root == NULL) {

      // If the list is empty, set the new item as the root

      list->root = newItem;

      list->root->id = newItem->id;

    } else {

      // Traverse to the end to add the new item and update IDs

      Item *current = list->root;

      while (current->next != NULL) {

	newItem->id++;

	current->next->id = newItem->id;

	current = current->next;

      }



      current->next = newItem;

      newItem->id++;

      current->next->id = newItem->id;

    }

    globalid = newItem->id; // Update the global ID tracker

  }

}


// Retrieve a specific item (token) from the history list by ID

char *get_history(List *list, int id) {

  Item *current = list->root;

  while (current != NULL) {

    if (current->id == id) {

      return current->str;

    }

    current = current->next;

  }

  return NULL; // Return NULL if the ID is not found

}

// Print the entire history list with each item's ID and string content

void print_history(List *list) {

  Item *current = list->root;

  printf(" ");

  while (current != NULL) {

    printf("ID:%d ", current->id);

    printf("%s ", current->str);

    current = current->next;

  }

  printf("\n");

}



// Free memory by releasing all items in the history list

void free_history(List *list) {

  Item *holder;

  Item *current = list->root;

  while (current) {

    holder = current;

    current = current->next;

    free(holder); // Free memory for each item

  }

}

