#include <stdio.h>
#include <stdlib.h>

typedef struct list_element{
  long value;
  struct list_element *next;
} *element_t;

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

  element_t newEntry = malloc(sizeof(*newEntry));
  newEntry->value = 4;
  newEntry->next = NULL;

  list->next = newEntry;
          // hier erstellen wir einen neuen Listeneintrag diesem Eintrag geben
          // wir den Wert 4. Danach fügen wir ihn als erstes Element unserer Liste ein

  element_t newEntry2 = malloc(sizeof(*newEntry));
  newEntry2->value = 5;
  newEntry2->next = NULL;

  newEntry->next = newEntry2;
          // hier das gleiche nochmal für ein zweites Element. Diesmal fügen wir es
          // als den Nachfolger des ersten Elements ein. (newEntry->next = newEntry2)

  printList(list);
  return 0;
}
