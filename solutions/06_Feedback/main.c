#include <stdio.h>

/*
*	Nothing special over here I think. Because of th condition we need to check
*	switch won't help us.
*/

int main(void){
	char c;
	printf("Please enter a charakter\n");
	scanf(" %c", &c);
	if(c < 32){
		printf("The char you entered is a: control charakter\n");	
	}else if(c < 48){
		printf("The char you entered is a: special charakter\n");
	}else if(c < 58){
		printf("The char you entered is a: number\n");	
	}else if(c < 65){
		printf("The char you entered is a: special charakter\n");
	}else if(c < 91){
		printf("The char you entered is a: upper case charakter\n");
		printf("The lower case charakter is: %c\n", c + 32);		
	}else if(c < 97){
		printf("The char you entered is a: special charakter\n");
	}else if(c < 123){
		printf("The char you entered is a: lowe charakter\n");
		printf("The upper case charakter is: %c\n", c - 32);
	}else
		printf("The char you entered is a: special charakter\n");
	return 0;
}