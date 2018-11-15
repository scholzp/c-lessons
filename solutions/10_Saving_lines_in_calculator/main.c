#include <stdio.h>

/*
*	This example uses a simple switch case statement. The input of the operand
*	is a char. As we know, chars are only numbers of at least 8 bits length. This
*	means, that we can compare them to the numbers from a ASCII - table.
*	The only tricky thing is th space in front of %c from the last scanf. This
*	is to cosume the last newline after you hit enter.
*	The keywords only differ in the first letter, so we only have to check this one.
*/

// calculate sum
float add(float a, float b){
	return a + b;
}

//calculate product
float mult(float a, float b){
	return a * b;
}

//calculate remainder
float mod(float a, float b){
	if(b == 0){
		printf("Can't divide by 0!\n");
		return 0;
	}
	return (int) a % (int) b;
}

int main(void){
	float result;
	float op_1, op_2;
	char operation[10];
	printf("Please enter first operand: \n");
	scanf("%f", &op_1);
	printf("Please enter second operand: \n");
	scanf("%f", &op_2);
	printf("Enter operation (+,-,*,/,%% or add, substract, multiply, divide, remainder): \n");
	scanf(" %10s", operation);
	//     ^------ space to consume the newline.
	switch(operation[0]){
		//add
		case 'A' :
		case 'a' :
		case '+' :
				result = add(op_1, op_2);
				break;
		//Sub
		case 'S' :
		case 's' :
		case '-' :
				result = add(op_1, 0 - op_2);
				break;
		//Mult
		case 'M' :
		case 'm' :
		case '*' :
				result = mult(op_1, op_2);
				break;
		//Div
		case 'D' :
		case 'd' :
		case '/' :
				if(op_2)
					result = mult(op_1, (1/op_2));
				else
					printf("Can't divide by 0!\n");
				break;
		//Remainder
		case 'R' :
		case 'r' :
		case '%' :
				result = mod(op_1, op_2);
				break;
		default : printf("Unkown operation: %s\n", operation);
	}
	//print result
	printf("The result is: %f\n", result);

	return 0;
}
