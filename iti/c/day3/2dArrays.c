/*
 * File: 2dArrays.c
 * -------------
 * Get sum of rows & Average of cols
 */

 #include <stdio.h>
 #include <conio.h>

 #define ROWS 3
 #define COLS 4

 void main()
 {
	int i, j, array[ROWS][COLS];
	int sum[ROWS] = {0};
	float avg[COLS] = {0}, total;


	clrscr();


	// get grades of each stud and find total for each one.
	for (i = 0; i < ROWS; i++)
	{
		printf("\nStudent[%d]:\n", i + 1);
		for (j = 0; j < COLS; j++)
		{
			printf("Course[%d]: ", j + 1);
			scanf("%d", &array[i][j]);
			sum[i] += array[i][j];
		}
	}
	// compute avg of grades in each course
	for (i = 0; i < COLS; i++)
	{
		total = 0;
		for (j = 0; j < ROWS; j++)
			total+= array[j][i];
		avg[i] = total / ROWS;
	}

	// display the results
	printf("Sum of grades for each stud\n");
	for (i = 0; i < ROWS; i++)
		printf("Student %d = %d\n", i + 1, sum[i]);

	printf("\nAverages of grades in each course\n");
	for (i = 0; i < COLS; i++)
		printf("Course %d = %.2f\n", i + 1, avg[i]);

	getch();
 }
