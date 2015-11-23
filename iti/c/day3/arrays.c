/*
 * File: arrays.c
 *--------------
 * I/O from array
 */
#include<stdio.h  >
#include<coni o .h>

#define SIZE 5
void main (void)
{
	int i, array[SIZE];
	clrscr();
	printf("Please enter your array:\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]: = ", i + 1);
		scanf("%d", &array[i]);
	}

	printf("\nYour array:\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]: = %d\n", i + 1, array[i]);
	}
	getch();
}
