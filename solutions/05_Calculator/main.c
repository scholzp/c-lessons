#include <stdio.h>

/*
*	This example uses a simple switch case statement. The input of the operand
*	is a char. As we know, chars are only numbers of at least 8 bits length. This 
*	means, that we can compare them to the numbers from a ASCII - table.
*	The only tricky thing is th space in front of %c from the last scanf. This
*	is to cosume the last newline after you hit enter.
*	The keywords only differ in the first letter, so we only have to check this one.
*/
int main(void){
	float result;
	int op_1, op_2; 
	char operation[10];
	printf("Please enter first operand: \n");
	scanf("%d", &op_1);
	printf("Please enter second operand: \n");
	scanf("%d", &op_2);
	printf("Enter operation (+,-,*,/,%% or add, substract, multiply, divide, remainder): \n");
	scanf(" %s", &operation);
	//     ^------ space to consume the newline.
	switch(operation[0]){
		case 43 : result = op_1 + op_2; break;
		case 97 : result = op_1 + op_2; break;
		case 45 : result = op_1 - op_2; break;
		case 115: result = op_1 - op_2; break;
		case 42 : result = op_1 * op_2; break;
		case 109: result = op_1 * op_2; break;
		case 47 : result = op_1 / op_2; break;
		case 100: result = op_1 / op_2; break;
		case 37 : result = op_1 % op_2; break;
		case 114: result = op_1 % op_2; break;
		default : printf("Unkown operation: %c\n", operation);
	}
	printf("The result is: %f\n", result);


	return 0;
}