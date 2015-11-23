#include<stdio.h>
#include<conio.h>

void main (void)

{
	int x;
	clrscr();
  printf("Please enter an integer: ");
	scanf("%d", &x);
	printf("\nThe Octal is %o and Hexa is %x of %d.", x, x, x);
	getch();
}
