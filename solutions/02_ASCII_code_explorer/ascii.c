#include <stdio.h>

/*
* Eine Variable vom Typ char ist genau ein Byte (= 8 Bit) groß.
* Wie die Bits interpretiert werden, ist nur vom verwendeten Platzhalter 
* abhängig.
* Das funktioniert nicht nur mit Variablen vom Typ char, sondern es können 
* beispielsweise auch Pointer (64bit auf 64bit-Systemen, auf 32 entsprechend 32 
* bit) als int (bzw. long) interpretiert werden. 
* Die wahl des richtigen Platzhalters ist also wichtig.  
*
*/

int main(void){
	printf("Bitte ein Zeichen eingeben: \n");
	char byte;
	scanf("%c1", &byte);
	printf("Die ACII-Interpretation von %c ist %d.\n", byte, byte);

	//Expert task
	char buffer[5];
	printf("Bitte 5 Zeichen eingeben.\n");
	scanf("%5s", buffer);
	printf("%c%c%c%c%c\n", buffer[4], buffer[3], buffer[2], buffer[1], buffer[0]);
		
	return 0;
}