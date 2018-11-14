#include <stdio.h>

/*
* f(0) = 0
* f(1) = 1
* f(2) = 1
* f(n) = f(n+1) + f(n-2) for all n > 2
*
*/

int fib(int n){
  int result = 1;
  if(n > 2){
    result = fib(n-1) + fib(n-2);
  }else if (n == 0){
    result = 0;
  }
  return result;
}

int main(void){
  int n;
  printf("Please enter a number\n");
  scanf("%i", &n);
  printf("The fibonacci number of %3d is %10d\n", n, fib(n));
  return 0;
}
