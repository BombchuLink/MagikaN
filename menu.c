#include <stdio.h>
#include <ncurses.h>
#include "main.h"
#include "menu.h"
#include "strings.h"

char MenuLines = 5;
bool Highlight = true;
char SubMenuMode = 0;
int winpad = 11;
char option[20];
int ch, i = 0, width = 10;

char** menu = NULL;
char *ListMenuMain[6] = { "Continue", "Load", "New", "Options", "About", "Quit" };
char *ListMenuAbout[3] = { "Magika-N", "Version 0.1", "Made By BLink"};

char MenuMode = 0;

void MainMenu(void) {
	menu = ListMenuMain;
	bool InitMenu = true;
	bool RefreshMenu = true;
	while (MenuMode >= 0) {

		if (InitMenu) {
			InitMenu = false;
			werase(w);
			wrefresh(w); // update the terminal screen
			MenuMode = 1;
		}

		if (RefreshMenu) {
			RefreshMenu = false;
			werase(w);
			box( w, 0, 0 ); // sets default borders for the window
			mvwprintw(w, 0, 8, "Welcome To Magika-N!");
			PrintMenuOptions();
		}

		/*
		if (ch != 0) {
			//pressing any button
			mvwprintw(w, 0, 8, "Welcome To Magika-N!");
			if (MenuMode == 5) {
				MenuMode = 0;
			}
		}
		*/

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
			case '\n':;
				if (i = 6) {
					ExitGame = true;
				}
				else {
					Mode = i+1;
				}
				MenuMode = -1;
				//RefreshMenu = true;
				//i = 0;
				break;
			case 'q':;
				MenuMode = -1;
				ExitGame = true;
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

		// q exits program
		if (ExitGame == false) {
			if( (ch = wgetch(w)) == 'q'){
				ExitGame = true;
				Mode = -1;
			}
		}
	}
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

