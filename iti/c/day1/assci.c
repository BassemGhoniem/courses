#include <stdio.h>
#include <conio.h>

void main() {
	char ch;
	clrscr();
	printf("Please enter char: ");
	scanf("%c", &ch);
	printf("\nThe ASCII value of character %c is %d.", ch, ch);
	getch();
}
