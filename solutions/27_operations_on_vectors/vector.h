#include <stdio.h>

struct vector {
  float *values;
  size_t size;
};

struct vector *addVectors(struct vector *first, struct vector *second);
void printVector(struct vector *v);
int readVectorFromInput(struct vector *v, FILE *stream);
