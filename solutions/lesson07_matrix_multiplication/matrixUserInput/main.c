/*
This code is part of the solutions from the c lessons of the ifsr.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
* the following macros are used for the buffer size. The buffers could be dynammical
* allocated for growing if needed. However this would add complexety to this
* programm which is only an example of how dynammic user input could be handeled.
*/
//sets the max lenght of one line
#define BUFFER_SIZE 80
//defines max matrix size
#define MAX_ARRAY_WIDTH 20
#define MAX_ARRAY_HEIGHT 20

//only for example. Use bool.h instead if you do a real project
enum bool {FALSE = 0, TRUE = 1};

// struct for matrices
struct matrix{
  size_t height;
  size_t width;
  double *values;
};

/*
* Allocates the the whole struct with the given sizes and returns a pointer to
* the ready to use struct.
*/
struct matrix * createMatrix(size_t width, size_t height){
  struct matrix * result = malloc(sizeof (struct matrix));
  result->width  = width;
  result->height = height;
  size_t matrixBytes = sizeof(double) * width * height;
  result->values = malloc(matrixBytes);
  memset(result->values, 0, matrixBytes);
  return result;
}

/*
* Frees all allocated memory. It is important, that for every malloc call one
* (and ONLY ONE) free() call exists.
* The stdlib malloc() implementation manages a 'table' wit allocated memory and
* the pointers to it. free() uses the same table to release the memory.
* This happens all with system calls, so the two can also fail if your OS is
* mean! You could check the return value of malloc() and verify, that it's not
* a NULL pointer malloc() returns (Althrough no one does this...).
*/
void destroyMatrix(struct matrix * m){
  free(m->values);
  free(m);
}

/*
* atof will return 0 if an error occures. This function will check if the
* returned 0 is the result of an error or of a succefull conversion.
*
* The first argument is the pointer to the string. This is done for performance,
* as we don't want to copy n Bytes. Of course, if the strings length is less
* than 8, it would be faster to copy it instead of a 8 Byte adddress
* (64 bit systems and 4 Byte = 32 bits on a 32 bit System).
*
* The second argumt is the address on which the result is written. This is a
* often used workaround when you want to return multiple values, let' say a
* boolean and a double.
*
* We can use the returned boolean to check, if the conversion was succefull.
*/
enum bool saveAtof(char *str[], double *dst){
  // try to convert str to double
  double result = atof(*str);
  // initialize some variables
  enum bool flag = FALSE;
  size_t x = 0;

  // check if the result is 0. This could point to a potential error or the
  // result is 0. Let's checkt this.
  if(result == 0){
    // We skip all line endings and check the remaining chars
    while(((*str)[x] != '\0') && ((*str)[x] != '\n')){
      // If we find one char which isn't '0' (48 in ASCII), it is TRUE, that
      // there was an error.
      if((*str)[x] != 48){
        flag = TRUE;
        break;
      }
      ++x;
    }
    //if the string was empty or wasn't convertable to 0, return false
    if((x == 0) || flag) {
      return FALSE;
    }
  }
  // If we didn' find any error but we got 0 as result, it (hopefully) must
  // have been the number 0, which we can now return.
  *dst = result;
  return TRUE;
}

/*
* This function does the actull input handling
*/
struct matrix *scanMatrix(char *separator){
  //creating buffers. Could be done wiht malloc too, maybe you try it...
  size_t maxArraySize = MAX_ARRAY_WIDTH * MAX_ARRAY_HEIGHT;
  double valueBuffer[maxArraySize];
  char lineBuffer[BUFFER_SIZE];
  /*
  * memset() sets the number of its 3rd argument bytes to it's second argument.
  * The start address is the first argument. Used to initialize memory.
  */
  memset(valueBuffer, 0, maxArraySize * sizeof(double));
  memset(lineBuffer, '\0', BUFFER_SIZE);
  char *number = NULL;
  size_t readWidthCurrent, readHeight, readWidthMax;
  readWidthCurrent = readWidthMax = readHeight = 0;

  //read a line of max BUFFER_SIZE bytes
  int valueBufferIndex = 0;
  enum bool NoEscape = TRUE;
  //let's start the input handling...
  do{
    // Read one line (when shorter) or BUFFER_SIZE-1 chars. On error, NULL is returned.
    if(fgets(lineBuffer, BUFFER_SIZE, stdin)!= NULL){
      /*
      * strtok() copies the string to the k-th char, where k+1 is the first
      * appearance of separator, and returns a pointer to this string.
      * If there is only '\0' left, a NULL pointer is returned.
      */
      number = strtok(lineBuffer, separator);
      while (number != NULL){
        // use the self defined aatof function, which returns a bool value (which is an int)
        if(saveAtof(&number, &valueBuffer[valueBufferIndex])){
          //if conversion was succefull, inc the number of read doubles
          ++readWidthCurrent;
        }else{
          //.. if not succefull, set the flag to false and leave this loop.
          NoEscape = FALSE;
          break;
        }
        /*
        * strtok maintains a static string, which will be set if the first argument
        * isn't a NULL pointer.
        * If the first argument is a NULL pointer, this static string will be used
        * and on each call, the part from the start the first occurance of
        * separator will be used to create a new string. A pointer to this string
        * will be returned and the part will be deleted from the static string.
        */
        number = strtok(NULL, separator);
        // We safed one double number to our buffer, so we must inc the index counter
        // if we don't want to override it...
        ++valueBufferIndex;
        /*
         * simple check, if we reached the end of our buffer. If we want to read more
         * values, we would have to allocate more memory. This would be a perfect
         * place to use a linked list, if you want to try it.
         * This simple example doesn't and return with an (really simple) error instead.
         */
        if(valueBufferIndex >= maxArraySize){
          printf("To many numbers in input. Try again with less numbers!\n");
          return NULL;
        }
      }
      // We have read a line, let's check if this was the first one.
      if(readHeight == 0){
        // If so, set the line lenght in elements for this matrix.
        readWidthMax = readWidthCurrent;
      }else{
        // If not, check if the length fit the lenght of the first line
        if((readWidthCurrent != readWidthMax) && NoEscape){
          printf("All lines must have the same number of elements (separated by %s)\n", separator);
          return NULL;
        }
      }
      // reset the counter of elements we have read.
      readWidthCurrent = 0;
      // inc the counter of the hight of the matrix.
      // This happens too, if we actually want to escape the loop...
      ++readHeight;
    }else{
      //print error message if fgets returned NULL
      printf("ERROR occured while reading!\n");
    }
  }while(NoEscape);
  // As mentioned before, we increment the counter even on escape, so let's fix it.
  --readHeight;

  // And finally create the matrix we have read.
  struct matrix* result = createMatrix(readWidthMax, readHeight);
  size_t matrixSize = result->height * result->width *  sizeof(double);
  /*
  * Like memset, the function memcpy is part of the header string.h.
  * It copies the number of bytes of it's third arg from the pointer from arg 2 to
  * arg 1. Does work with more than strings.
  */
  memcpy(result->values, valueBuffer, matrixSize);
  /*
  This could be used as alternative:
  for(int x = 0; x < matrixSize; ++x){
    result->values[x] = valueBuffer[x];
  }
  */
  //And we can return our brand new matrix.
  return result;
}

/*
* Simple print function for matrix struct
*/
void print_matrix(struct matrix *m){
  size_t line = 0;
  printf("Matrix %p with:\n", m);
  printf("Width = %lu, Height = %lu\n", m->width, m->height );
  for(size_t y = 0; y < m->height; ++y){
    printf("| " );
    for(size_t x = 0; x < m->width; ++x){
      printf("%9.3f | ", m->values[line + x]);
    }
    line += m->width;
    printf("\n");
  }
}

/*
* This function multiplies two matrices and prints the result matrix.
* If we want to store it somewhere, we would have to use pointers as there
* is no way to return a VLA (variable length array).
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  // create the result matrix
  if(b->height == a->width){
    struct matrix *result = createMatrix(b->width, a->height);
    for(size_t n = 0; n < a->height; ++n){
      for(size_t m = 0; m < b->width; ++m){
        for(size_t l = 0; l < a->width; ++l){
          result->values[n * b->width + m] += a->values[n * a->width + l] * b->values[l * b->width + m];
        }
      }
    }
    printf("The result is:\n");
    print_matrix(result);
    destroyMatrix(result);
  }else{
    printf("Matrices have wrong format. Height of matrix A: %lu, Width of B: %lu\n", a->height, b->width);
  }
}

int main(void) {

  struct matrix *matrixA, *matrixB;
  matrixA = matrixB = NULL;
  printf("Please enter matrices. Press enter after each line. Emty lines stop the input.\n");
  printf("First matrix\n");
  matrixA = scanMatrix(",\0");
  printf("\nSecond matrix\n");
  matrixB = scanMatrix(",\0");

  /*
  *  If scanMatrix() failed, NULL will be returned.
  *  We must not attempt to access any member variable if they are invalid. This
  *  would result in a crash, or even worse, could make your programm exploitable.
  *  ALWAYS be sure, that you work with valid memory.
  */
  if((matrixA == NULL) || (matrixB == NULL)){
    printf("Error in input! One or more matrices were NULL!\n");
  }else{
    printf("Matrix A:\n");
    print_matrix(matrixA);
    printf("\nMatrix B:\n");
    print_matrix(matrixB);

    matrix_mult(matrixA, matrixB);

    //Releas all allocted memory
    destroyMatrix(matrixA);
    destroyMatrix(matrixB);
  }

  return EXIT_SUCCESS;
}
