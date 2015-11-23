/*
 * File: stackTest.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>

 #include "stack.h"
 #include "stack.c"

 #define LINES 4
 #define STR_SIZE 20

// some keys codes
#define ESC 27
#define ENTER 13
#define HOME 71
#define END 79
#define UP 72
#define DOWN 80
#define ENTER 13


 node * createNode(int value);

 void main() {
	char menu[LINES][STR_SIZE] = {"Pop",
								  "Push",
								  "View",
								  "Exit"};
	char key;
	int current = 0, i = 0, item, preItem;
	node * myNode;
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
				switch (current)
				{
					case 0:
						if (pop())
								printf("Done!\n");
						else
							printf("The stack is empty!");
						break;
					case 1:
						printf("Please enter an integer to push: ");
						scanf("%d", &item);
						push(createNode(item));
						break;

					case 2:
						view();
						break;

					case 3:
						printf("GOOD BYE");
						break;
				}

				getch();
				break;
		}
   }
   while (current != (LINES - 1) || key != ENTER);

}


node * createNode(int value)
{
	node * listNode;
	listNode = (node *) malloc(sizeof(node));
	listNode->value = value;
	listNode->next = listNode->pre = NULL;
	return listNode;
}

