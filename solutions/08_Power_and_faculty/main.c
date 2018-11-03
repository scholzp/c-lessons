#include <stdio.h>

/*
*	...and loops again. Everything else is basic mathemathics.
*
*/

int main(void){
	int a, b;
	long long result;
	printf("Please enter the first number: \n");
	scanf("%d", &a);
	printf("Please enter the second number: \n");
	scanf("%d", &b);
	//a power b	
	result = 1;
	for(int i = 0; i < b; ++i)
		result *= a;
	printf("a ^ b = %lld\n", result);
	// b power a	
	result = 1;
	for(int i = 0; i < a; ++i)
		result *= b;
	printf("b ^ a = %lld\n", result);
	// faculty of a
	result = 1;
	for(int i = 0; i < a; ++i)
		result *= i + 1;
	printf("a! = %lld\n", result);
	// faculty of b
	result = 1;	
	for(int i = 0; i < b; ++i)
		result *= i + 1;
	printf("b! = %lld\n", result);
	
	return 0;
}