#include<stdio.h>
#include<conio.h>

void main (void)
{
	int sum = 0;
	int value;
	clrscr();
	printf("This program add values up to 100\n\n");
	do
	{
		printf("value? ");
		scanf("%d", &value);
		sum += value;
	}
	while (sum <= 100);
	printf("\nsum = %d\n", sum);
	getch();
}
