#include <stdio.h>

int main(void){
  /*
  * Altrough this might not look nice, it's the only why to not be typing
  * for 10 years. Surely you can initialize the array like c = {'L', 'o', 'r', ...}
  * but this will take a while an won't look nice either.
  * So at least we learn how we can write everything on one line while using
  * more than one in our source...
  *
  * The little '\' at the end of each line does the trick. The compiler will
  * interpret this as one line while you are acutually using more than one. this
  * is important in this example as the compiler will produce errors if the
  * init string isn't written on one line. The string will be nullterminated if
  * enters as string ("string"). With chars only you might need '\0'. Just try it.
  */

  char text[] = {"Lorem ipsum dolor sit amet, consetetur sadipscing elitr,\
sed diam nonumy eirmod tempor invidunt ut labore et,\
dolore magna aliquyam erat, sed diam voluptua. At vero,\
eos et accusam et justo duo dolores et ea rebum."};

  int i = 0;
  while(text[i] != '\0'){
    printf("%c", text[i]);
    ++i;
  }
  printf("\n");
  return 0;
}
