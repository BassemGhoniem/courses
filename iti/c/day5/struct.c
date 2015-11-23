/*
 * File: struct.c
 * --------------
 *  create Employee Data type and read & write its members
 */

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

#define STRLEN 81
#define SIZE 6
#define P_SIZE 12
#define ALIGN  20


typedef struct {
	int code;
	char name[STRLEN];
	int age;
	int salary;
	int overtime;
	int deduction;
} Employee;

typedef struct {
	int x;
	int y;
} pos;

void main() {
	Employee e;
	pos locations[SIZE];
	char menu[SIZE][P_SIZE] = {"Code: ", "Name: ", "Age: ", "Salary: ",
								"Overtime: ", "Deduction: "};
	int i, y = 2, x;
	clrscr();
	printf("Please enter emp data:-\n");
	for (i = 0; i < SIZE; i++) {

		if (i % 2) {
			x = ALIGN;
		} else {
			x = 1;
			++y;
		}
		gotoxy(x, y);
		locations[i].y = y;
		locations[i].x = x + P_SIZE;
		cprintf("%s", menu[i]);
	}
	printf("\r");
	for (i = 0; i < SIZE; i++) {
		gotoxy(locations[i].x, locations[i].y);
		switch (i) {
			case 0 : scanf("%d", &e.code); 	    break;
			case 1 : scanf("%s", e.name);       break;
			case 2 : scanf("%d", &e.age);       break;
			case 3 : scanf("%d", &e.salary);    break;
			case 4 : scanf("%d", &e.overtime);  break;
			case 5 : scanf("%d", &e.deduction); break;
		}
	}
	printf("\nThe employss's data :-\n");
	printf("Code: %d\n", e.code);
	printf("Name: %s\n", e.name);
	printf("Net Salary: %d\n", e.salary - e.deduction + e.overtime);
	getch();
	printf("\r");

}
