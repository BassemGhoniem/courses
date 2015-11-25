/*
 * File: extendedKeys.c
 * -------------
 * Determine normal & extented keys from user input
 */

 #include <stdio.h>
// #include <conio.h>

 void main() {
	char key;
	//clrscr();
	do {
		printf("Please press key (Esc to exit): ");
		key = getchar();
		if (key)
			printf("\n\nYou typed normal key\nits code is %d\n\n", key);
		else
			printf("\n\nYou typed extented key \nits code is: %d\n\n", getchar());
	} while (key != 27);
 }
