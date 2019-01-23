#include <stdio.h>
#include <stdlib.h>

struct list_element{
  long value;
  struct list_element *next;
};

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
          // Datentypen (list_t).
  list->value = 0;
  list->next = NULL;
          // jetzt wo wir unseren Pointer haben, der auf die Liste im Heapspeicher
          // zeigt können wir diese befüllen. Auf ein Attribut der Liste können wir
          // entweder so "(*list).value" oder so "list->value" zugreifen.
  return 0;
}
