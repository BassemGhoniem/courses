/*
 * File: stringFN.c
 * -------------
 * Take the first name & last name
 * Display full name;
 */

 #include <stdio.h>
 #include <conio.h>
 #include <string.h>
 #define SIZE 30

 void main() {
	int index = 0;
	char name[SIZE], fullName[SIZE];
	clrscr();
	printf("First Name: ");
	scanf("%s", name);
	strcpy(fullName, name);
	strcat(fullName, " ");
	printf("Last Name: ");
	scanf("%s", name);
	strcat(fullName, name);
	printf("Your Full Name is: %s\n", fullName);
	getch();
 }
