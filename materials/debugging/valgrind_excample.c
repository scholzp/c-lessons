#include <stdio.h>

void a(int n){
  if(n == 0)
    return;
  a(n);
}

void b(int n){
  a(n);
}

void c(int n){
  b(n);
}

void d(int n){
  c(n);
}


int main(void){
  int n = 10;
  d(n);
  return 0;
}
