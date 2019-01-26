#include <stdlib.h>
#include <stdio.h>

struct list_element{
  int value;
  struct list_element *next;
};

void printList(struct list_element *list){
  while (list != NULL) {
    printf("Element: %d\n", list->value);
    list = list->next;
  }
}

void append(struct list_element **list, int value){
  struct list_element *current = *list;
  while(*list != NULL){
    list = &((*list)->next);
  }
  *list =  malloc(sizeof(*current));
  (*list)->value = value;
  (*list)->next = NULL;
}

int main(void){
  struct list_element *list = NULL;
  int *p = malloc(sizeof(*p));
  int x;
  append(&list, 52);
  append(&list, 86);
  append(&list, 56);
  append(&list, 81);
  printList(list);

  return EXIT_SUCCESS;
}
