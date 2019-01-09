#include <stdio.h>

// As enum values are always a integer, there can be no enum such as Pi, which
// is some kind of floating point value...
#define PI 3.14159

// Struct as known from task 21 \o/
struct circle {
  float radius;
  float circumference;
  float area;
};

/*  The dereference operator * tells the compiler, that we expext a memory
*   address as parameter, which points to an area of data of the size of a float.
*   Because we only got the adress of the memory we want to work with, we have
*   derefence it, so we can acess the memory. This is done with the *-operator
*   too. Now we can write to memory which is acutally not in the scope of
*   calcCircle. This means, it wont be destroyed too, if we leave the function,
*   althrough the pointer itself will be destroyed.
*/
void calcCircle(float radius, float *circumference, float *area){
  *circumference = 2 * PI * radius * radius;
  *area = 2 * PI * radius;
}
int main(void){
  struct circle c;
  printf("Please enter a radius: ");
  /*  Know from scanf the &-operator does the referencing. It does not take the
  *   actuall value of the variabel but it's memory address and creates a
  *   reference.
  */
  scanf("%f", &c.radius);
  printf("Value of radius: %f, Memory Address of radius: %p\n",
          c.radius, &c.radius);
  calcCircle(c.radius, &c.circumference, &c.area);
  printf("--------------- Circle Data ----------------\n");
  printf("Radius:        %.2f\n", c.radius);
  printf("Circumference: %.2f\n", c.circumference);
  printf("Area:          %.2f\n", c.area);
  printf("--------------------------------------------\n");

  return 0;
}
