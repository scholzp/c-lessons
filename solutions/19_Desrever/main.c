#include <stdio.h>
// We will use strlen() and memset() from string.h
#include <string.h>

// The size of our Buffer and the max. lenght+1 of the string
// We can solve his on many way. If we want to change the length,
// we only have to change this value.
#define BUFFER_SIZE 80

int main(void) {
  char input[BUFFER_SIZE], reversed[BUFFER_SIZE];
  // Initialiezing is important. Because we initialize the whole strings with
  //'\0', especial the reversed string, we don't need to bother with setting the
  // termination symbol when we copy (unsless the whole string is overwritten).
  memset(input, '\0', BUFFER_SIZE);
  memset(reversed, '\0', BUFFER_SIZE);


  fgets(input, BUFFER_SIZE, stdin);

  size_t pos = 0;
  /*
  * This part is a bit tricky. As we use size_t, we actually work with an unsinged
  * long int. This means, if x is 0 and we execute --x, x will be the max. of
  * site_t (unsigned long).
  * Therefore the loop for(site_t x = strlen(input); x >= 0; --x) would be endless.
  * This is why we subtract 1 in line 36 instead of changing the condition.
  * strlen() will return the lenght of the string without the termination ('\0')
  * char and we must not copy '\0' it, because the string ends with this one and
  * printing it may result in something different than you would expect.
  */
  for(size_t x = strlen(input); x > 0; --x){
    // The if(...) statement is used to drop leading '\n'. You enter one at the
    // end of input, when you are done with the input and press the enter key.
    if( !( (pos == 0) && (input[x - 1] == '\n')) ){
      reversed[pos] = input[x - 1];
      ++pos;
    }
  }
  // The output.
  printf("----------------------------------------------------------------\n");
  printf("Input:\n%s\n", input);
  printf("Reversed string:\n%s\n", reversed);
  printf("----------------------------------------------------------------\n");

  return 0;
}
