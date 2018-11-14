#include <stdio.h>

int fac(int n){
  int result = 1;
  if(n > 1){
    result = n * fac(n-1);
  }
  return result;
}

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
  printf("Please enter a number:\n");
  scanf("%i", &n);
  printf("Factorial of %d is %d\n", n, fac(n));
  printf("Factorial of %d is %d\n", n, fib(n));
  return 0;
}
