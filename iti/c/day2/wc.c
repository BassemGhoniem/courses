#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;
	int words = 0, letters = 0, inWord = 0;
	clrscr();
	printf("Please type some words\n");

	ch = getche();
	while (ch != 13)
	{
		letters++;
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			if (!inWord)
			{
				inWord = 1;
				words++;
			}
		}
		else
		{
			inWord = 0;
		}
		ch = getche();
	}
	printf("You typed %d words and %d letters.\n", words, letters);
	getch();
}