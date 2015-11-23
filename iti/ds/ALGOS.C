#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define COPIES 3
void readValues(int * intArrays[], int arraySize);
void printValues(int * intArrays[], int arraySize);
int linearSearch(int array[], int arraySize, int value);
int binarySearch(int array[], int arraySize, int value);
void bubble(int array[], int arraySize);
void selection(int array[], int arraySize);
void insertion(int array[], int arraySize);

void main(void)
{
	int * intArrays[COPIES], i, arraySize, value;
	clrscr();
	printf("This program sorts and searches integer values!\n");
	printf("please give me number of values you wish to deal with: ");
	scanf("%d", &arraySize);

	for(i = 0;i < COPIES; i++)
		intArrays[i] = (int *) malloc(sizeof(int) * arraySize);
	readValues(intArrays, arraySize);

	printf("Enter number to search for? (linear search): ");
	scanf("%d", &value);
	if (linearSearch(intArrays[0], arraySize, value) != -1)
		printf("Found !\n");
	else
		printf("Not Found!\n");
	getch();
	printValues(intArrays, arraySize);
	printf("\nSorting Array 1 using bubble....\n");
	bubble(intArrays[0], arraySize);
	printValues(intArrays, arraySize);

	printf("\nSorting Array 2 using selection....\n");
	selection(intArrays[1], arraySize);
	printValues(intArrays, arraySize);

	printf("\nSorting Array 3 using insertion....\n");
	insertion(intArrays[2], arraySize);
	printValues(intArrays, arraySize);


	printf("Enter number to search for? (binary search): ");
	scanf("%d", &value);
	if (linearSearch(intArrays[0], arraySize, value) != -1)
		printf("Found !\n");
	else
		printf("Not Found!\n");

	getch();
}

void readValues(int * intArrays[], int arraySize)
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		printf("Value [%d] = ", i + 1);
		scanf("%d", &intArrays[0][i]);
	}
	for (i = 1; i < COPIES; i++)
		memcpy(intArrays[i], intArrays[0], arraySize * sizeof(int));
}


void printValues(int * intArrays[], int arraySize)
{
	int i, j;
	for (i = 0; i < COPIES; i++)
	{
		printf("Array [%d] :-\n", i);
		for (j = 0; j < arraySize; j++)
			printf("%d ", intArrays[i][j]);
		printf("\n");
	}
}

int linearSearch(int array[], int arraySize, int value) {
	int i;
	for (i = 0; i < arraySize; i++)
		if (array[i] == value)
			return i;
	return -1;
}
int binarySearch(int array[], int arraySize, int value){
	int last = arraySize - 1;
	int first = 0, mid;
	while (first <= last) {
		mid = (last + first) / 2;
		if (array[mid] == value)
			return mid;
		if (array[mid] > value)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble(int array[], int arraySize)
{
	int swaps = 1, index = 0, i;
	while (swaps)
	{
		for (i = swaps = 0, index++; i < arraySize - index; i++)
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swaps = 1;
			}
	}
}
void selection(int array[], int arraySize)
{
	int i, j, min;
	for (i = 0; i < arraySize - 1; i++)
	{
		min = i;
		for ( j =  i + 1; j < arraySize; j++)
			if (array[min] > array[j])
				min = j;
		if (min != i)
			swap(&array[min], &array[i]);
	}
}
void insertion(int array[], int arraySize)
{
	int i, index, curValue;

	for ( i = 0; i < arraySize - 1; i++)
	{
	  index = i + 1;
	  curValue = array[index];
	  while(index >= 0 && array[--index] > curValue) {
		array[index + 1] = array[index];
	  }
	  array[index + 1] = curValue;
	}
}
