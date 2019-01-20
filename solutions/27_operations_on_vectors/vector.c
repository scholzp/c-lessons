#include "vector.h"

struct vector* addVectors(struct vector *first, struct vector *second) {
  if(first->size ==  second->size) {
    struct vector *result = calloc(1, sizeof(*result));
    result->value = calloc(first->size, sizeof(*result->value));
    result->size = first->size;
    for(size_t x = 0; x < first->size; ++x) {
      result->value[x] = first->value[x] + second->value[x];
    }
    return result;
  }
  return NULL;
}

void printVector(struct vector *v) {
  for(size_t x = 0; x < v->size; ++x)
    printf("%f\n", v->value[x]);
}

int readVectorFromStdin(struct vector *v) {
  const char allocSize = 10;
  int input = 0;

  size_t stringLen = allocSize;
  size_t index = 0;
  char *str = calloc(stringLen, sizeof(*str));
  do{
    input = fgetc(stdin);
    if((input < '0' || input > '9') && input != '.' && input != ',') {
      return -1;
      break;
    }else{
      if(index >= strinLen){
        stringLen += allocSize;
        char *new = realloc(str, strinLen);
        if(new != NULL)
          str = new;
      }
      str[index] = input;
      ++index;
    }
  }
  while(input != '\n')
}
