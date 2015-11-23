#include<stdio.h>
#include<conio.h>

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main (void)
{
	int x, y;
	clrscr();
	printf("This program swaps two values\n");
	printf("X = ");
	scanf("%d", &x);
	printf("Y = ");
	scanf("%d", &y);
	swap(&x, &y);
	printf("\nX = %d\n", x);
	printf("Y = %d\n", y);
	getch();
}
