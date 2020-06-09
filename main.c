#include <stdio.h>
#include <ncurses.h>
#include "main.h"
#include "menu.h"
#include "strings.h"


bool ExitGame = false;

char Mode = 0;
WINDOW *w;

int main(int argc, char *argv[])
{
	initscr(); // initialize Ncurses
	noecho();
	//cbreak(); //don't want for keypress to update
	w = newwin( 8, 35, 0, 0 ); // create a new window
	keypad(w, TRUE); // enable keyboard input for the window.
	curs_set(0); // hide the default screen cursor.

	while(ExitGame == false) {
		switch (Mode) {
			case 0:; //Main Menu
				MainMenu();
				break;
			case 1:;
				//LoadLastGame();
				break;
			case 2:;
				//NewGameMenu();
				break;
			case 3:;
				//LoadGameMenu();
				break;
			case 4:;
				//ViewSpellList();
				break;
			case 5:;
				//OptionsMenu();
				break;
			case 6:;
				//AboutMenu();
				break;
		}
	}
	delwin(w);
	endwin();
}
