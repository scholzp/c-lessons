#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
* Nothing special about this one. We use the power and square root function
* from math.h, so we need to add the -lm switch to our compile command like:
* gcc -o test main.c -lm
* This says the linker to link against the math library.
*/

struct complex{
  double re;
  double im;
};

void printAbsolute(struct complex c){
  const double result =  sqrt(pow(c.re, 2.0) + pow(c.im, 2.0));
  printf("Absolute value: %lf\n", result);
  return;
}

int main(void){
  struct complex number;
  printf("Enter a complex number\n");
  printf("Please enter real part\n");
  scanf("%lf", &number.re);
  // im part
  printf("Please enter imaginary part\n");
  scanf("%lf", &number.im);
  // print absolute
  printAbsolute(number);


  return EXIT_SUCCESS;
}
