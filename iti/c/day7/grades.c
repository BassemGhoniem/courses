/*
 * File: grades.c
 * -------------
 * Get sum of rows & Average of cols
 */

 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>



 void main()
 {
	int i, j, rows, cols, **array, *sum;
	float *avg, total;

	//int i, j, array[ROWS][COLS];
	//int sum[ROWS] = {0};
	//float avg[COLS] = {0}, total;


	clrscr();
	printf("Please give me number of students:-\n");
	scanf("%d", &rows);
	printf("How many courses per student:-\n");
	scanf("%d", &cols);

	array = (int**) malloc(sizeof(int*) * rows);
	for (i = 0; i < rows; i++)
		array[i] = (int*) malloc(sizeof(int) * cols);
	sum = (int*) malloc(sizeof(int) * rows);
	avg = (float*) malloc(sizeof(float) * cols);

	// get grades of each stud and find total for each one.
	for (i = 0; i < rows; i++)
	{
		printf("\nStudent[%d]:\n", i + 1);
		sum[i] = 0;
		for (j = 0; j < cols; j++)
		{
			printf("Course[%d]: ", j + 1);
			scanf("%d", &array[i][j]);
			sum[i] += array[i][j];
		}
	}
	// compute avg of grades in each course
	for (i = 0; i < cols; i++)
	{
		total = 0;
		for (j = 0; j < rows; j++)
			total+= array[j][i];
		avg[i] = total / rows;
	}

	// display the results
	printf("Sum of grades for each stud\n");
	for (i = 0; i < rows; i++)
		printf("Student %d = %d\n", i + 1, sum[i]);

	printf("\nAverages of grades in each course\n");
	for (i = 0; i < cols; i++)
		printf("Course %d = %.2f\n", i + 1, avg[i]);

	getch();
 }
