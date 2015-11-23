/*
 * File: menu.c
 * -------------
 * Highlighted menu
 */
 #include <stdio.h>
 #include <conio.h>

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

 void main() {
	char menu[LINES][STR_SIZE] = {"New", "Display", "Exit"};
	char key;
	int current = 0, i = 0;

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
				cprintf("\r%s\n", menu[current]);
				getch();
				break;
		}
   }while (current != (LINES - 1) || key != ENTER);

}
