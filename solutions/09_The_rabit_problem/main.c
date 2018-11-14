#include <stdio.h>

/*
* f(0) = 0
* f(1) = 1
* f(2) = 1
* f(n) = f(n+1) + f(n-2) for all n > 2
*
*/

int main(void){
  int n, last, second_last, result;
  printf("Please enter a number\n");
  last = 0;
  second_last = 0;
  result = 1;
  scanf("%i", &n);
  for(int i = 1; i < n; ++i) {
    second_last = last;
    last   = result;
    result = last + second_last;
  }
  printf("The fibonacci number of %3d is %10d\n", n, result);
  return 0;
}
