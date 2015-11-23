																																					/*
 * File: treeTest.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include "tree.h"
 #include "tree.c"

 #define LINES 6
 #define STR_SIZE 20

// some keys codes
#define ESC 27
#define ENTER 13
#define HOME 71
#define END 79
#define UP 72
#define DOWN 80
#define ENTER 13



 void main() {
	char menu[LINES][STR_SIZE] = {"Add",
								  "Delete",
								  "search",
								  "Display All",
								  "Display Root",
								  "Exit"};
	char key;
	int current = 0, i = 0, item, preItem;
	BSTNode *tree = NULL;

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
						printf("Please enter an integer to add: ");
						scanf("%d", &item);
						insertNode(&tree, item);
						break;
					case 1:
						printf("Please give me node to delete: ");
						scanf("%d", &item);
						removeNode(tree, item);
						break;
					case 2:
						printf("Please enter an integer to search for: ");
						scanf("%d", &item);
						if (findNode(tree, item))
							printf("Found!\n");
						else
							printf("Not Found!\n");
						break;
					case 3:
						displayTree(tree);
						break;
					case 4:
						displayRoot(tree);
						break;
					case 5:
						printf("GOOD BYE");
						break;
				}

				getch();
				break;
		}
   }
   while (current != (LINES - 1) || key != ENTER);

}
