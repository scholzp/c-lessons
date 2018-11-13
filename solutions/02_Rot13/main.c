#include <stdio.h>

/*
*	The specifier controls how the char c is interpreted when printed.
*	Actually char is a number with the size of at leat 8 bit. So arithmetics
*	can be performed with casting ot conversion.
*
*/

int main(void){
	unsigned char c;
	printf("Please enter a character to encrypt. \n");
	scanf("%c", &c);
	//upper case letters
	if(c > 64 && c < 91){
		c += 13;
		if(c > 90)
			c -= 90 + 65;
	//lower case letters
	}else if(c > 97 && c < 123){
		c += 13;
		if(c > 123)
			c -= 123 + 97;
	//evrything else
	}else
		c += 13;
	//Print encrypted letter
	printf("Enrypted with %c\n", c);
	return 0;
}
