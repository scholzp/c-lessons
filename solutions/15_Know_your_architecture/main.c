#include <stdio.h>

/*
* Nicht schön, aber dafür auch nicht spannend.
*
*/

int main(void){
  printf("\nSize of Datatypes in your sytsem:\n");
  printf("+----------------+---------------+--------------+\n");
  printf("| Type name      | Size in Bytes | Size in Bits |\n");
  printf("|----------------+---------------+--------------|\n");
  printf("| %14s | %13ld | %12ld |\n", "char",
                    sizeof(char),       sizeof(char) * 8);
  printf("| %14s | %13ld | %12ld |\n", "int",
                    sizeof(int),        sizeof(int) * 8);
  printf("| %14s | %13ld | %12ld |\n", "long",
                    sizeof(long),       sizeof(long) * 8);
  printf("| %14s | %13ld | %12ld |\n", "long long",
                    sizeof(long long),  sizeof(long long) * 8);
  printf("| %14s | %13ld | %12ld |\n", "float",
                    sizeof(float),      sizeof(float) * 8);
  printf("| %14s | %13ld | %12ld |\n", "double",
                    sizeof(double),      sizeof(double) * 8);
  printf("| %14s | %13ld | %12ld |\n", "long double",
                    sizeof(long double), sizeof(long double) * 8);
  printf("+----------------+---------------+--------------+\n");
  return 0;
}
