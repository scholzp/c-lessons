#include <stdio.h>
#include <stdlib.h>

typedef struct list_element{
  long value;
  struct list_element *next;
} *element_t;

void append (element_t list, long number){
  while (list->next != NULL){
    list = list->next;
  }
  element_t newEntry = malloc(sizeof(*newEntry));
  newEntry->value = number;
  newEntry->next = NULL;
  list->next = newEntry;
}

void pushFront(element_t list, long number){
  element_t newEntry = malloc(sizeof(*newEntry));
      // Hier ist ein kleiner Kunstkniff nötig, da wir nicht so leicht den POinter
      // der auf "list" zeigt überschreiben können. Somit können wir nicht wirklich ein
      // Element vor dem ersten Listenelement einfügen. Was wir aber machen können,
      // ist ein Element nach dem ersten Element einzufügen und diesem neuen
      // Element den Wert vom ersten Element zu geben. Anschließen wird list->value
      // mit dem neuen Wert überschrieben.

  newEntry->value = list->value;
  newEntry->next = list->next;
  list->value = number;
  list->next = newEntry;
}

void printList(element_t list) {
  printf("---------------------- List Content -----------------------------\n");
  printf("Elements:\n");
  while(list != NULL) {
    //printf("| %p | --> | %p | --> | %p |\n", elem->prev, elem, elem->next);
    printf("%li\n", list->value);
    list = list->next;
  }
  printf("-----------------------------------------------------------------\n");
}

int main(void) {
  element_t list;
          // ein neuer pointer der auf eine Liste zeigen kann wird erzeugt
          // Die Liste selbst existiert hier noch nicht.

  list = malloc(sizeof(*list));
          // mit malloc wird jetzt der speicher für eine Liste auf dem HEAP-speicher
          // reserviert. Malloc liefert dann den Pointer zurück der auf die angelegte
          // Liste zeigt. Dieser pointer wird dann in "list" geschrieben.

          // Note: Damit sizeof hier richtig funktioniert, benötigen wir den " * "
          // vor "list", da unsere Variable "list" vom typ pointer ist. Mit dem " * "
          // dereferenzieren wir den Pointer und erhalten den zugrunde liegenden
          // Datentypen (element_t).
  list->value = 0;
  list->next = NULL;
          // jetzt wo wir unseren Pointer haben, der auf die Liste im Heapspeicher
          // zeigt können wir diese befüllen. Auf ein Attribut der Liste können wir
          // entweder so "(*list).value" oder so "list->value" zugreifen.
  pushFront(list, 45);
  append(list, 4);
  append(list, 7);
  append(list, 4);
  append(list, 9);
  append(list, 4);
  append(list, 1);
  pushFront(list, 36);


  printList(list);
  return 0;
}
