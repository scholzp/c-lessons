#include <stdio.h>
#include <stdlib.h> // <~~~ dazu weiter unten mehr

/*
* Bei dieser Übung ist maximal das print-Statement vom 'Remainder' erwähnenswert.
* Die Escapsequenz '\n' dient der Interpretation von C-Strings. Ein '\%' bringt hier
* also nicht den gewünschten Effekt. Anders sieht das mit '%%' aus, da ein einziges
* '%' eine Escapesequenz für printf einleitet.
*
*/


int main(void) {
	int a, b;
	printf("Bitte Zahl 1 eingeben: ");
	scanf("%i", &a);
	printf("Bitte Zahl 2 eingeben: ");
	scanf("%i", &b);



	printf("Quotient : %6d / %6d = %6d\n", a, b, a / b);
	printf("Remainder: %6d %% %6d = %6d\n", a, b, a % b);

	/*
	Wenn der Rest und der Quotient benötigt werden, lohnt es sich, die in stdlib.h
	definierte Funktion div und den Typen div_t zu verwenden. Der Grund ist, dass
	Division sehr teuer ist (und mod noch teurer, hinsichtlich Rechenzeit), aber
	die Mod-Operation sowohl den Rest als auch den Quotienten berechnet und so eine
	Operation gespart werden kann. Daher ist der folgende Code besser in der
	Laufzeit (aber hat potentiell mehr Overhead wegen include von stdlib.h).

	div_t output = div(a,b);
	printf("Quotient : %6d / %6d = %6d\n", a, b, output.quot);
	printf("Remainder: %6d %% %6d = %6d\n", a, b, output.rem);
	*/

	printf("Sum      : %6d + %6d = %6d\n", a, b, a + b);
	printf("Differece: %6d - %6d = %6d\n", a, b, a - b);
	printf("Prodcut  : %6d * %6d = %6d\n", a, b, a * b);

	return 0;
}
