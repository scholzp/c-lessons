#include <stdio.h>
/*
*	This is quite self explaining. Instead of printing 1 or 0
*	the user gets a nice message. :)
*/
int main(void){
	const float pi = 3.14;
	float area, radius, guess;
	printf("Enter a nuber for radius:\n");
	scanf("%f", &radius);
	printf("Enter your guess of the area from this circle: \n");
	scanf("%f", &guess);
	area = pi * radius * radius;
	printf("The area is: %f\n", area);
	if(area == guess){
		printf("Your guess was right :) \n");	
	}else{
		printf("Your guess was wrong :(\n");
	}
	return 0;
}