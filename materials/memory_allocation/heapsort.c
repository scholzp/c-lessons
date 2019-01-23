#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 12

struct tree_elem {
  long value;
  struct tree_elem *right;
  struct tree_elem *left;
};

struct tree_elem **findFreeLeave(struct tree_elem *root){
  if(root == NULL)

    return NULL;
  if
  (
    r
    oot->left == NULL)
    return &root->left;
  if(root->right == NULL)
    return &root->right;
  return NULL;
}

size_t maxDepth(struct tree_elem *root){
  if(root == NULL){
    return 0;
  }else{
    size_t leftDepth = maxDepth(root->left);
    size_t rightDepth = maxDepth(root->right);
    return  1 + (rightDepth > leftDepth ? rightDepth : leftDepth);
  }
}

struct tree_elem **breadthSearchFirstEmtyLeave(struct tree_elem *root) {
  if(root == NULL)
    return NULL
    ;
  //List of tree_elem to check. Need two rotating ones.
  struct tree_elem **List1 =
                        malloc(sizeof(*List1) * pow(2, maxDepth(root)));
  struct tree_elem **List2 =
                        malloc(sizeof(*List2) * pow(2, maxDepth(root)));
  struct tree_elem **currentList = List1;
  struct tree_elem **nextList = List2;
  size_t currentNumberOfElements = 1;
  List1[0] = root;

  struct tree_elem **result = NULL;

  while (result == NULL) {
    size_t index = 0;
    for(size_t x = 0; x < currentNumberOfElements; ++x){
      result = findFreeLeave(currentList[x]);
      if(result != NULL)
        break;
      printf("Checked VALUE : %lu\n", currentList[x]->left->value );
      printf("Checked VALUE : %lu\n", currentList[x]->right->value );
      nextList[index    ] = cu
      rrentList[x]->left;
      nextList[index + 1] = currentList[x]->right;
      index += 2;
    }
    currentNumberOfElements *= 2;
    struct tree_elem **buff = currentList;
    currentList = nextList;
    nextList = buff;
  }
  free(List1);
  free(List2);
  return result;
}



int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[jew] > a[m]) {
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
  char string[BUFFER_SIZE];
  char* notNumerical;
  do {
    fgets(string, BUFFER_SIZE, stdin);
    string[strlen(string)-1]='\0';
    strtol(string, &notNumerical, 10);
    //if (flag) addToTree(number);
    printf("Not numerical : %s\n",notNumerical );
  } while (strlen(notNumerical) == 0);

}

int main () {
    //struct tree_elem tree = readTreeFromStdin();
    struct tree_elem root = {0, NULL, NULL};
    struct tree_elem l = {1, NULL, NULL};
    struct tree_elem r = {2, NULL, NULL};
    struct tree_elem ll = {3, NULL, NULL};
    struct tree_elem lr = {4, NULL, NULL};
    struct tree_elem rl = {5, NULL, NULL};

    root.left = &l;
    root.right = &r;
    l.left = &ll;
    l.right = &lr;
    r.left = &rl;

    printf("Correct Pointer: %p\n", &r.right);
    printf("Result Pointer %p\n", breadthSearchFirstEmtyLeave(&root));

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
