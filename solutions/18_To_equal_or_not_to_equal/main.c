#include <stdio.h>

/*
* compile with: gcc -std=C99 -o<executeable> main.c
* We use VLAs (Variable Length Array) which are supported since C99-standard.
* The size of the array will be determined at run time and not at compile time
* like with fixed sizes.
* You have to declare the variable for the size before the declaration of the arry.
* This wont work with C++. (As C++ don't has VLA-Support).
*/


void print_int_array(size_t length, int arr[length]){
  for(size_t x = 0; x < length; ++x)
    printf("%5d", arr[x]);
  printf("\n");
}

int print_matrix(size_t total_size, int m[] ){
  int result = 1;
  printf("Your matrix looks like:\n");
   for(size_t x  = 0; x < total_size; ++x){
     //result = (m[x] != n[x]);
   }
}

int main(void){
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int matrice[2][3] = { {1, 2, 3},
                        {9, 8, 7}                    };

  size_t size_first_elem = sizeof(arr[0]);
  print_int_array(sizeof(arr) /size_first_elem, arr);
  print_matrix(2 * 3, &matrice);
  return 0;
}
