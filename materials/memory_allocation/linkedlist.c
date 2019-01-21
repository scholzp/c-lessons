#include <stdio.h>
#include <stdlib.h>

typedef struct list_elem *element_t;

/*
Ein deutscher Paketzusteller möchte herausfinden, wie viel Zeit eine frisch
eingestellte Kraft gegenüber einer langjährigen Mitarbeiterin benötigt. Dafür
möchte die Post ein C Programm, welches nacheinander Zustellzeiten in Minuten
einließt. Die Mitarbeiter wurden über eine Woche hinweg überwacht und jetzt
soll aus den Daten die durchschnittliche Zustellzeit berechnet werden.
Paktebote A (Frischling) hat zum Zustellen von 30 Paketen folgende Zeiten benötigt.
12
23
14
4
67
23
11
34
12
34
78
12
4
2
18
43
23
13
53
32
43
67
23
12
54
23
14
51
33
8
3
*/

struct list_elem{
  long value;
  element_t prev;
  element_t next;
};

typedef struct list {
  element_t last;
  element_t first;
  size_t size;
}list_t;

void append(list_t *list, long element) {
  element_t new = malloc(sizeof(*new));
  new->value = element;
  new->prev = NULL;
  new->next = NULL;
  if(list->first == NULL) {
    list->first = new;
  }
  if(list->last == NULL) {
    list->last = new;
  }else{
    list->last->next = new;
    new->prev = list->last;
    list->last = new;
  }
  ++list->size;
};

void pushFront(list_t *l, long element){
  element_t new = malloc(sizeof(*new));
  new->value = element;
  new->next = l->first;
  l->first->prev = new;
  l->first = new;
  ++l->size;
}

void destroyList(list_t *l) {
  element_t elem = l->first;
  element_t next;
  while(elem != NULL){
    next = elem->next;
    free(elem);
    elem = next;
  }
  free(l);
}

void insertAtIndex(list_t *list, size_t index, long element) {
  if(index >= list->size) {
    append(list, element);
  }else if (index == 0){
    pushFront(list, element);
  }else {
    element_t current = list->first;
    for(size_t x = 0; x < index; ++x)
      current = current->next;
    element_t new = malloc (sizeof(*new));
    printf("VALUE: %li\n", current->value);
    new->value = element;
    new->prev = current->prev;
    new->next = current;
    current->prev->next = new;
    current->prev = new;
    ++list->size;
  }
}

void printList(list_t *l) {
  element_t elem = l->first;
  printf("---------------------- List Summary -----------------------------\n");
  printf("Total size: %lu\n", l->size);
  printf("Elements:\n");
  while(elem != NULL) {
    //printf("| %p | --> | %p | --> | %p |\n", elem->prev, elem, elem->next);
    printf("%li\n", elem->value);
    elem = elem->next;
  }
  printf("-----------------------------------------------------------------\n");
}


int main(void) {
  list_t *list;
  list = malloc(sizeof(*list));
  list->size = 0;
  list->first = NULL;
  list->last  = NULL;
  printf("%p\n", list);

  append(list, 5);
  printList(list);
  append(list, 3);
  printList(list);
  append(list, 7);
  printList(list);
  pushFront(list, 9);
  printList(list);
  insertAtIndex(list, 0, 10);
  printList(list);


  destroyList(list);
  return 0;
}
