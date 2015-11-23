/*
 * File: linkedList.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>

 #include "linkedList.h"
 #include "linkedList.c"

 #define LINES 7
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
	char menu[LINES][STR_SIZE] = {"Add",
								  "Insert After",
								  "Display All",
								  "Display One",
								  "Delete One",
								  "Delete All",
								  "Exit"};
	char key;
	int current = 0, i = 0, item, preItem;

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
						printf("Please enter an integer: ");
						scanf("%d", &item);
						add(createNode(item));
						break;
					case 1:
						printf("Please enter an integer: ");
						scanf("%d", &item);
						printf("Insert After what ? ");
						scanf("%d", &preItem);
						insertAfter(createNode(item), search(preItem));
						break;

					case 2:
						displayAll();
						break;

					case 3:
						printf("Wich item you wanna display: \n");
						scanf("%d", &item);
						displayOne(search(item));
						break;
					case 4:
						printf("Please enter the item you wanna delete: ");
						scanf("%d", &item);
						deleteOne(search(item));
						break;
					case 5:
						deleteAll();
						printf("The list is empty now\n");
						break;
					case 6:
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
