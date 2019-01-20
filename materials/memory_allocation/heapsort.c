#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 12

enum bool{ FALSE = 0, TRUE = 1};

struct tree_elem {
  int value;
  struct tree_elem *right;
  struct tree_elem *left;
};

int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}

void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}

void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}
//
// enum bool convertToLong(char *input, long *dst) {
//   long number = atoi(input, (input + BUFFER_SIZE), 10);
//   enum bool flag = TRUE;
//   size_t index = 0;
//   *dst = number;
//   if(number == 0) {
//     while(input[index] != '\0'){
//         flag &= (input[index] == '0');
//     }
//   }
//   return TRUE && flag && index;
// }

struct tree_elem readTreeFromStdin (){
  struct tree_elem *root = malloc(sizeof(*root));
  long number;
  char string[BUFFER_SIZE];
  char* notNumerical;
  enum bool flag = FALSE;
  do {
    fgets(string, BUFFER_SIZE, stdin);
    string[strlen(string)-1]='\0';
    strtol(string, &notNumerical, 10);
    //if (flag) addToTree(number);
    printf("Not numerical : %s\n",notNumerical );
  } while (strlen(notNumerical) == 0);

}

int main () {
    struct tree_elem tree = readTreeFromStdin();
    //
    // int n = sizeof a / sizeof a[0];
    // int i;
    // for (i = 0; i < n; i++)
    //     printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    // heapsort(a, n);
    // for (i = 0; i < n; i++)
    // printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
