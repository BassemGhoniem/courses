#include <stdio.h>
#include <conio.h>

#define SIZE 5
void main() {
	int x[SIZE], i;
	int *p = x;
	clrscr();

	printf("This programs takes %d values and print them backwards\n", SIZE);
	for (i = 0; i < SIZE; i++, p) {
		printf("value [%d] = ", i + 1);
		scanf("%d", p++);
	}

	printf("\nYou typed this numbers :-\n");
	for (i = SIZE - 1, p--; i >= 0; i--)
		printf("value [%d] = %d\n", i + 1, *p--);
	getch();
}
