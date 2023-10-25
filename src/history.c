
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  List *list = malloc(sizeof(List));
  list ->root = malloc(sizeof(Item));
  return list;
}
void add_history(List *list, char *str){
  int pos = 1;
  Item *tmp = list->root;

  while(tmp->next){
    tmp = tmp->next;
    pos++;
  }
}
