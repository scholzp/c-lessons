#include <stdio.h>

// Enum for direction
enum direction {
  LEFT,
  RIGHT
};

//The swap function using pointers to write the values back to it's paramters
void swap (float *a, float *b){
  float buffer;
  buffer = *a;
  *a = *b;
  *b = buffer;
}

//rotate just using swap multiple times, using the enum direction
void rotate(float *a, float *b, float *c, enum direction d){
  if(d == LEFT){
    swap(a, b);
    swap(b, c);
  }else{
    swap(c, b);
    swap(b, a);
  }
}

int main(void){
  float a, b, c;
  // input
  printf("Enter three number: \n");
  printf("Number 1: ");
  scanf("%f", &a);
  printf("Number 2: ");
  scanf("%f", &b);
  printf("Number 3: ");
  scanf("%f", &c);
  // output
  printf("Current Order: %f, %f, %f\n", a ,b, c);
  swap(&a, &b);
  printf("Current Order after swap: %f, %f, %f\n", a ,b, c);
  rotate(&a, &b, &c, LEFT);
  printf("After rotating left %f, %f, %f\n", a ,b, c);

  return 0;
}
