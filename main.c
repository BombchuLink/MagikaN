#include <stdio.h>
#include <ncurses.h>
#include "menus.h"


char MenuMode = 0;
char MenuLines = 4;
bool Highlight = true;
char SubMenuMode = 0;

WINDOW *w;
int winpad = 11;
char option[20];

void PrintMenuOptions(void);

int main(int argc, char *argv[])
{
	menu = ListMenuMain;
	int ch, i = 0, width = 10;
	initscr(); // initialize Ncurses
	noecho();
	w = newwin( 7, 35, 0, 0 ); // create a new window
	box( w, 0, 0 ); // sets default borders for the window
	mvwprintw(w, 0, 8, "Welcome To Magika-N!");
	// now print all the menu options and highlight the first one
	PrintMenuOptions();
	wrefresh(w); // update the terminal screen
	i = 0;
	noecho(); // disable echoing of characters on the screen
	keypad(w, TRUE); // enable keyboard input for the window.
	curs_set(0); // hide the default screen cursor.

	// get the input
	int MenuModeLastCycle;
	while( (ch = wgetch(w)) != 'q'){

		if (MenuMode != MenuModeLastCycle) {
			switch (MenuMode) {
				case 0:; // Main Menu
					break;
				case 1:; //Continue game
					break;
				case 2:; //Load game
					break;
				case 3:; //New game
					break;
				case 4:; //Options
					break;
				case 5:; //About
					menu = ListMenuAbout;
					MenuLines = 2;
					Highlight = false;
					break;
			}
			werase(w);
			box( w, 0, 0 ); // sets default borders for the window
			PrintMenuOptions();
		}

		MenuModeLastCycle = MenuMode;

		if (ch != 0) {
			//pressing any button
			if (MenuMode == 5) {
				MenuMode = 0;
			}
		}

		sprintf(option, "%-7s",  menu[i]);
		mvwprintw( w, i+1, winpad, "%s", option );
		switch(ch) {
			case 'k':
				i--;
				if ( i < 0) {
					i = MenuLines;
				}
				break;
			case 'j':
				i++;
				if ( i > MenuLines) {
					i = 0;
				}
				break;
			/*
			case 'h':;
				 switch(MenuMode) {
					case 0:
						 //exit program
						 break;
					case 5:
						 //back out of info
						 MenuMode = 0;
						 i = 0;
						 break;
				 }
			*/
			case '\n':;
				MenuMode = i+1;
				i = 0;
				break;
			default:;
				break;
		}

		if (Highlight) {
			wattron( w, A_STANDOUT );
			sprintf(option, "%-7s",  menu[i]);
			mvwprintw( w, i+1, winpad, "%s", option);
			wattroff( w, A_STANDOUT );
		}
	}
	delwin(w);
	endwin();
}

void PrintMenuOptions(void) {
	// now print all the menu options and highlight the first one
	for (int i=0; i<MenuLines+1; i++) {
		if(i == 0 && Highlight)
			wattron( w, A_STANDOUT ); // highlights the first option.
		else
			wattroff( w, A_STANDOUT );
		sprintf(option, "%-7s",  menu[i]);
		mvwprintw( w, i+1, winpad, "%s", option );
	}
	wrefresh(w); // update the terminal screen
}
