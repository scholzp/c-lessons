#include <stdio.h>
#include <time.h>

/*
* This is just to show differneces in comptuting time with different aritmethic operations.
* If there are no diffecreces between them your compile might optimze to well and withdraw 
* the calculation (as a is never used).
*/

int main(void){
  clock_t start, end;
  //add
  printf("Clocks per second:    %10ld\n", CLOCKS_PER_SEC);
  start = clock();
  for(int i = 1; i < 100000000; ++i){
    int a = 99999999999 + i;
  }
  end = clock();
  printf("Add clock:            %10ld\n", end - start);

  //Mult
  start = clock();
  for(int i = 1; i < 100000000; ++i){
    int a = 99999999999 * i;
  }
  end = clock();
  printf("Multiplikation clock: %10ld\n", end - start);

  // devide
  start = clock();
  for(int i = 1; i < 100000000; ++i){
    int a = 99999999999 / i;
  }
  end = clock();
  printf("Divide clock:         %10ld\n", end - start);

  //divide with multiplicative inverse
  start = clock();
  for(int i = 1; i < 100000000; ++i){
    int a = 99999999999 * (1/i);
  }
  end = clock();
  printf("Div with invers clock:  %10ld\n", end - start);

  // mod
  start = clock();
  for(int i = 1; i < 100000000; ++i){
    int a = 99999999999 % i;
  }
  end = clock();
  printf("Modulo clock:         %10ld\n", end - start);


  return 0;
}
