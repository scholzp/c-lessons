#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653

struct point {
  float xValue;
  float yValue;
};

struct circle {
  struct point center;
  float radius;
  float circumference;
  float area;
};

struct circle createCircle(struct point center, float radius) {
  struct circle result;
  result.center = center;
  result.radius = radius;
  result.circumference = 2 * PI * radius;
  result.area = PI * radius * radius;
  return result;
}

void printCircle (struct circle c) {
  printf("------------- Circle Data ---------------------\n");
  printf("Center:         X = %f, Y = %f\n", c.center.xValue, c.center.yValue);
  printf("Radius:         %f\n", c.radius);
  printf("Circumference:  %f\n", c.circumference);
  printf("Area:           %f\n", c.area);
  printf("-----------------------------------------------\n");
}

int main(void) {
  struct point p = {0, 0};
  float radius = 0;
  printf("Create center of circle 1:\n");
  printf("Enter x coordinate:\n");
  scanf(" %f", &p.xValue);
  printf("Enter y coordinate:\n");
  scanf(" %f", &p.yValue);

  printf("Enter radius of circle 1:\n");
  scanf(" %f", &radius);

  struct circle c = createCircle(p, radius);
  printCircle(c);

  return EXIT_SUCCESS;

}
