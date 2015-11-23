/*
 * File: queueTest.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>

 #include "queue.h"
 #include "queue.c"

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
	char menu[LINES][STR_SIZE] = {"Dequeue",
								  "Enqueue",
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
						if (dequeue())
							printf("done!");
						else
							printf("The queue is empty!\n");
						break;
					case 1:
						printf("Please enter an integer to enqueue: ");
						scanf("%d", &item);
						enqueue(createNode(item));
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

