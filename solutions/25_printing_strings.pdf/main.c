#include <stdio.h>

// Defines a preprocessor macro. Each occurance of BUFFER_SIZE will be replaced
// with 80 by the preprocessor. The compiler chooses the best fidding type.

#define BUFFER_SIZE 80

/*
*   As a c string is defined as zero terminated character sequence, we can
*   iterate through one until our pointer point to a char which is '\0'
*/

void printString(char *string){
  char *address = string;
  while (*address != '\0'){
    fputc(*address, stdout);
    ++address;
  }
}

void printStringSpaces(char *string){
  char *address = string;
  while (*address != '\0'){
    fputc(*address, stdout);
    // there is a newline at the end of the input, after which we don't want to
    // print a space.
    if(*address != '\n')
      fputc(' ', stdout);
    ++address;
  }
}

int main(void){
  char string[80];
  printf("Write up to 79 characters and press Enter!\n");
  fgets(string, BUFFER_SIZE, stdin);
  printf("You worte:\n");
  printString(string);

  printf("Now a little broken:\n");
  printStringSpaces(string);

  return 0;
}
