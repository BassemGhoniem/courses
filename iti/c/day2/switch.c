
#include <stdio.h>
#include <conio.h>

void main()
{
	char key;
	clrscr();
	do
	{
		clrscr();
		printf("A: Good Morning\n");
		printf("B: Good Evening\n");
		printf("C: Good Bye\n\n");

		printf("Enter your choice: ");
		key = getche();

		clrscr();
		switch (key)
		{
			case 'A':
				printf("Good morning\n");
				break;

			case 'B' :
				printf("Good Evening\n");
				break;

			case 'C' :
				printf("Good Bye\n");
				break;
			default :
				printf("Bad Choice\n");
				break;
		}
		getch();

	}
	while ( key != 'C');
	getch();
}
