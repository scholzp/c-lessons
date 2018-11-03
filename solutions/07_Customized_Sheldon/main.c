#include <stdio.h>

/*
*	Is this still a thing?
*	Not much to see here, only two loops and some basic I/O.
*	You can use the possiblity to evaluate an int as bool. It is simple 'flase'
*	if the int is equal to zero, else 'true'.
*
*/

int main(void){
	int knocks, iterations;
	printf("How many knocks per iteratio?\n");
	scanf(" %d", & knocks);
	printf("How many iterations?\n");
	scanf(" %d", &iterations);
	for(int x = 0; x < iterations; ++x){
		for(int y = 0; y < knocks; ++y){
			if(!y)			
			 printf("Knock");
			else
			 printf(", knock");		
		}
		printf(" - Penny?\n");
	}
	return 0;
}