#include <stdio.h>
/*
*   Argc is the count of given command line paramters. It is at least one, as
*   the programm's name is given as first parameter to main, if the programm is
*   called.
*   The folling n paramters can be found in agrv, which is basically an array
*   of strings (char arrays).
*/
int main(int argc, char* argv[]){
  if (argc > 1){
    for(int x = 1; x < argc; ++x){
      printf("Greeting to %s\n", argv[x]);
    }
  }
  return 0;
}
