#include <stdio.h>
#include <math.h>
/*
* compile this with
*   gcc -o <filename> main.c -lm
*
* As the library libm is not linked by defoult you will need the -lm switch.
*/
int main(void){
  int n, max_width_result;
  printf("Enter a number :\n");
  scanf("%i", &n);
  printf("\n");
  /*
  *  Determime how many decimal digits will be needed
  *  we will need +2 for the space
  */
  max_width_result = log10(n * n) + 2;

  //calculate and print table
  for(int y = 0; y <= n; ++y){
    printf("%*d", max_width_result, y) ;
    for(int x = 1; x <= n; ++x){
      if(y == 0){
        printf("%*d", max_width_result, x) ;
      }else{
        printf("%*d", max_width_result, y*x) ;
      }
    }
    printf("\n");
  }
  return 0;
}
