/*
 * File: depts.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>
#define LINES 3
#define STR_SIZE 20

// some keys codes
#define ESC 27
#define ENTER 13
#define HOME 71
#define END 79
#define UP 72
#define DOWN 80
#define ENTER 13



#define STRLEN 81
#define SIZE 6
#define P_SIZE 12
#define ALIGN  20


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




void displayMenu(const char menu[][P_SIZE] , pos *locations, int n, int j, int y);
Employee readEmpData(const pos *locations);
void printEmpData(Employee e, int j);


 void main() {
	char menu[LINES][STR_SIZE] = {"New", "Display", "Exit"};
	char key;
	int current = 0, i = 0;
	char cardMenu[SIZE][P_SIZE] = {"Code: ", "Name: ", "Age: ", "Salary: ",
								"Overtime: ", "Deduction: "};
	Employee **employees;
	pos *locations;

	int y = 4, emps, depts, deptNo, *empsNoArr;
	clrscr();
	printf("Please give me the numbers of departments: ");

	scanf("%d", &depts);
	employees = (Employee **) malloc(sizeof(Employee*) * depts);
	for (i = 0; i < depts; i++)
		employees[i] = NULL;
	empsNoArr = (int*) malloc(sizeof(int) * depts);


	do {
		clrscr();
		for (i = 0; i < LINES; i++) {
			if (current == i) {
				textcolor(CYAN + BLINK);
				cprintf("\r%s\n", menu[i]);
			} else {
				textcolor(WHITE);
				cprintf("\r%s\n", menu[i]);
			}
		}

		key = getch();
		if (!key)
			key = getch();
		switch (key) {
			case UP:
				current = (current + LINES - 1) % LINES;
				break;
			case DOWN:
				current = ++current % LINES;
				break;
			case END:
				current = LINES - 1;
				break;
			case HOME:
				current = 0;
				break;
			case ENTER:
				clrscr();
				textcolor(WHITE);
				switch (current) {
					case 0:
						printf("Enter dep no: ");
						scanf("%d", &deptNo);
						deptNo--;
						if (deptNo > -1 && deptNo < depts)
						{
							printf("No of emps: ");
							scanf("%d", &emps);
							empsNoArr[deptNo] = emps;
							employees[deptNo] = (Employee*) malloc(emps * sizeof(Employee));
							locations = malloc(emps * SIZE * sizeof(pos));

							for (i = 0; i < emps; i++)
							{
								displayMenu(cardMenu, locations + i, SIZE, i, y);
								employees[deptNo][i] = readEmpData(locations + i);
								y = locations[i + SIZE - 1].y + 2;
							}
						}
						else
						{
							printf("You don't have this department\n");
						}

						break;
					case 1:
						clrscr();
						printf("Enter dep no: ");
						scanf("%d", &deptNo);
						deptNo--;
						if (depts > -1 && deptNo < depts) {
							if (employees[deptNo]) {
								for (i = 0; i < empsNoArr[deptNo]; i++)
									printEmpData(employees[deptNo][i], i);
							} else {
								printf("This department does not have any employees!\n");
							}
						} else {
							printf("You don't have this department\n");
						}


						break;
					case 2:
						cprintf("\rGOOD BYE\n");
						break;
				}

				getch();
				break;
		}
   } while (current != (LINES - 1) || key != ENTER);

}




void displayMenu(const char menu[][P_SIZE], pos *locations, int n, int j, int y) {
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


Employee readEmpData(const pos *locations) {
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
