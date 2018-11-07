#include <stdio.h>

/*
*	The specifier controls how the char c is interpreted when printed.
*	Actually char is a number with the size of at leat 8 bit. So arithmetics
*	can be performed with casting ot conversion.
*
*/

int main(void){
	char letter;  //Hier wird eine neue Variable des Datentyps "char" erstellt. Der Name der Variablen ist "letter".

	printf("Bitte geben Sie einen Buchstaben ein: "); //Ein bisschen Text, um dem Nutzer zu zeigen, was er machen muss
	scanf("%c", &letter); /*scanf steht für "scan formatted" und bedeutet, dass der
	vom Nutzer eingegebene Text mit dem Datentyp formatiert wird, den wir angeben.
	In diesem Beispiel ist der Datentyp char, was durch %c festgelegt wird. Wenn
	ihr einen anderen Datentyp einlesen wollt, schaut in die Tabelle mit den %Zeichen.

	Nach dem Komma steht die Variable, an die wir nun unseren eingelesenen Datentyp übergeben wollen.
	Um das erfolgreich zu machen, müssen wir uns die Speicheradresse der Variablen holen. Dafür ist das "&" da.
	Damit sagen wir nun dem Computer: Schreibe unseren neuen eingelesenen Wert genau
	an die Speicherstelle, wo unsere Variable Letter liegt.*/

	// -> da Letter jetzt unseren eingelesenen Wert enthält, können wir damit arbeiten

	/* Als nächstes wollen wir unseren eingelesenen letter um 13 Zeichen verschieben.
	Aus einem A soll also zum Beispiel ein N werden. Da ein Character vom Computer
	als Zahl verstanden wird (A=65,B=66, usw.), können wir das einfach mit Addition machen.*/

	letter = letter + 13; /* Hier wird unserer Variablen letter ein neuer Wert zugewiesen,
	der aus dem alten Wert von letter + 13 besteht.*/

	printf("Ihr Buchstabe wurde mithilfe von Rot13 zu folgendem konvertiert: %c\n", letter);
	/*printf steht für print formatted (analog zu scanf) und dient dazu formatierten Text auszuprinten.
	Dabei werden ebenfalls wie bei scanf die gleichen Platzhalter mit dem %Zeichen verwendet.
	Hierbei erfolgt das Ganze jedoch in die andere Richtung. Wir sagen dem Computer also:
	Hol dir den Wert,der in der Variablen letter drin steht und ersetze das %c mit diesem Wert.

	Man kann auch mehrere Platzhalter hintereinander verwendenen. Muss dann aber
	auch die Variablen in der richtigen Reihenfolge angeben:

	Bsp.:
	printf("BuchstabeA: %c, BuchstabeB: %c", letterA, letterB)
	letterA würde hier an die Stelle des ersten %c geschrieben werden. letterB folglich
	an die Stelle des zweiten %c.

	Ich hoffe, dass euch das etwas geholfen hat.*/



	return 0;
}
