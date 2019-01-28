#include <stdio.h>

int power(int base, int exponent) {
	int result = 1;
	int count  = 0;
	while(count < exponent)
		result *= base;
		++count;
	return result;
}

int main(void) {
	int a = 2, b = 8;
	printf("%d^%d = %d", a, b, power(a,b));	
	return 0;
}