#include <stdio.h>

/*
* stdio.h wird für printf benötigt.
* buffer benötigt 13 Byte Speicher für cr.
* %d = Platzhalter für Ganzzahl (decimal)
* %c = Platzhalter für Char
*/

int main(void){
	char buffer[13] = "Hello World!\n";
	printf("%s", buffer);

	//Expert-Task
	printf("%c%d%d%d%d %c%d%c%d%d%c%c\n", 
		'H', 3 , 1, 1, 0, 'W', 0 ,'|', 2, 1, 'd', '!');
	return 0;
}
