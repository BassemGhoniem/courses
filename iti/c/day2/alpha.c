#include<stdio.h>
#include<conio.h>

void main (void)
{
	char ch;
	clrscr();
	printf("This program prints A-Z\n\n");
	for (ch = 'A'; ch <= 'Z'; ch++)
		printf("%c ", ch);
	getch();
}
