#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(size_t width, size_t height, int (*matrix)[height][width]){
  for(size_t y = 0; y < height; ++y){
    for(size_t x = 0; x < width; ++x){
      (*matrix)[y][x] = 0;
    }
  }
}

void print_matrix(size_t width, size_t height, int matrix[height][width]){
  for(size_t y = 0; y < height; ++y){
    printf("| " );
    for(size_t x = 0; x < width; ++x){
      printf("%6d | ", matrix[y][x]);
    }
    printf("\n");
  }
}

void matrix_mult(size_t width_A, size_t height_A, size_t width_B, \
                int A[height_A][width_A], int B[width_A][width_B])
{
  // create the result matrix
  int result_matrix[width_B][height_A];
  init_matrix(width_B, height_A, &result_matrix);

  for(size_t n = 0; n < height_A; ++n){
    for(size_t m = 0; m < width_B; ++m){
      for(size_t l = 0; l < width_A; ++l){
        result_matrix[m][n] += A[n][l] * B[l][m];
      }
    }
  }
  printf("-------------------------------------------\nC:\n");
  print_matrix(width_B, height_A, result_matrix);

}


int main(void){
  /*
  size_t is an alias for unsinged ints defined in stdlib.h. It's generaly used
  as type for variables usd to descripte the size of elemnts to make the code
  more readable.
  Equivalent to: int heightA, heightB...
  */

  size_t height_A, width_A, width_B;
  height_A = 4000;
  width_A  = 600;
  width_B  = 6;

  int array_A[height_A][width_A];
  int array_B[width_A][width_B];

  // lets initiate our matrices with random values
  time_t t;
  time(&t);
  /*
  to get a more usefull seed we take the current time, safe it to an object
  of time_t and convert it and it's adress to int and long (as this was
  written on a 64bit system and therefore a memory adress is 64bit long.
  This will yield a compiler warning maybe).
  */
  srand((int)t * (long)(&t));
  for(size_t x = 0; x < width_A; ++x){
    //initiate matrix A with dimensions widthA, heightA with random numbers
    for(size_t y = 0; y < height_A; ++y){
      array_A[y][x] = rand() % 200;
    }
    //initiate matrix B with dimensions widthB, widthA with random numbers
    for(size_t y = 0; y < width_B; ++y){
      array_B[x][y] = rand() % 200;
    }
  }
  printf("Matrix A:\n");
  print_matrix(width_A, height_A, array_A);

  printf("Matrix B:\n");
  print_matrix(width_B, width_A, array_B);

  //lets call our multiply function;
  matrix_mult(width_A, height_A, width_B, array_A, array_B);

  /*
  Macro defined in stdlib.h which indicates termination after succesful
  completion of the programm. Equivalent to return 0, but if you read this
  one the source literaly screems "SUCCESS!!".
  */
  return EXIT_SUCCESS;
}
