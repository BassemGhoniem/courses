/*
 * File: string.c
 * -------------
 * user should enter character by character in string
 * and upon pressing enter display that string
 */



#include <stdio.h>
#include <conio.h>

#define SIZE 30
#define ENTER 13

void main (void)
{
	char str[SIZE], ch;
	int index = 0, i;
	clrscr();

	// reading string char by char
	printf("Please type some words\n");
	do
	{
		ch = getche();
		if (ch != ENTER)
			str[index++] = ch;
	} while(ch != ENTER && index < SIZE - 1);
	str[index] = '\0';

	// iform the user that he typed too long string
	if (index == SIZE - 1)
		printf("\n\nBTW, You typed too long string\n");

	// printing the string char by char
	printf("\n\nYou typed :-\n");
	for (i = 0;i < index;i++)
		printf("%c", str[i]);
	printf("\n");
	getch();
}
