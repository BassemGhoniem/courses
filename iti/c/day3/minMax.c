/*
 * File: minMax.c
 * -------------
 * Get min and max from array
 */

#include<stdio.h>
#include<conio.h>
#define SIZE 5
void main (void)
{
	int i, array[SIZE];
	int max = 0, min = 0;
	clrscr();
	printf("Please enter your array:\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]: = ", i + 1);
		scanf("%d", &array[i]);
	}

	// find min
	min = array[0];
	max = array[0];
	for ( i = 1; i < SIZE; i++)
		if (array[i] < min)
			min = array[i];
		else if (array[i] > max)
			max = array[i];

	printf("\n Min = %d, Max = %d", min, max);
	getch();
}
