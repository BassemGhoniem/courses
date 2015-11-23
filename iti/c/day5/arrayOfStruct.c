/*
 * File: arrayOfStruct.c
 * ---------------------
 *  creates array of emps data types
 */

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define STRLEN 81
#define SIZE 6
#define P_SIZE 12
#define ALIGN  20
#define EMPS 5

// employee and position data types
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




void displayMenu(const char menu[][P_SIZE] , pos locations[], int n, int j, int y);
Employee readEmpData(const pos locations[]);
void printEmpData(Employee e, int j);

void main() {
	Employee employees[EMPS];
	pos locations[EMPS][SIZE];
	char menu[SIZE][P_SIZE] = {"Code: ", "Name: ", "Age: ", "Salary: ",
								"Overtime: ", "Deduction: "};
	int i, y = 2;

	clrscr();
	for (i = 0; i < EMPS; i++) {
		displayMenu(menu, locations[i], SIZE, i, y);
		employees[i] = readEmpData(locations[i]);
		y = locations[i][SIZE - 1].y + 2;
	}
	for (i = 0; i < EMPS; i++)
		printEmpData(employees[i], i);


	getch();

}


void displayMenu(const char menu[][P_SIZE], pos locations[], int n, int j, int y) {
	int i, x;
	printf("\nPlease enter emp[%d] data:-\n", j + 1);
	for (i = 0; i < n; i++) {

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
}



Employee readEmpData(const pos locations[]) {
	int i;
	Employee e;
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
	return e;
}


void printEmpData(Employee e, int j) {
	printf("\nThe employss's[%d] data :-\n", j + 1);
	printf("Code: %d\n", e.code);
	printf("Name: %s\n", e.name);
	printf("Net Salary: %d\n", e.salary - e.deduction + e.overtime);
}
