#include <iostream>
#include <fstream>
#include <curses.h>
#include <menu.h>
#include "ScrollableMenu.h"

ScrollableMenu::ScrollableMenu (unsigned int height, 
		unsigned width, unsigned x, unsigned y) {

	this->height = height;
	this->width = width;
	this->x = x;
	this->y = y;

	items = (ITEM**) malloc (sizeof (ITEM*) * 5);

	for (auto i = 0; i < 5; i++) {
		items[i] = new_item ("hello", "world");
	}

	menu = new_menu ((ITEM**) items);

	window  = newwin (height, width, x, y);
	keypad (window, TRUE);
	set_menu_win (menu, window);
	set_menu_sub (menu, derwin (window, 6, 38, 0, 0));
	set_menu_format (menu, 5, 1);

	//  set_menu_mark (menu, " * ");

	box (window, 0, 0);

	post_menu (menu);
	panel = new_panel (window);

	nextMenu = nullptr;
}
ScrollableMenu::~ScrollableMenu () {
	unpost_menu (menu);
	free_menu (menu);

	for (auto i = 0; i < 50; i++) {
		free_item (items[i]);
	}
}

void ScrollableMenu::nextPanel (ScrollableMenu* sm) {
	set_panel_userptr (panel, sm->getPanel ());
	nextMenu = sm;
}

void ScrollableMenu::refreshSubsequentItems () {
	nextMenu->refresh ();
}

void ScrollableMenu::addItem (std::string title, std::string descr) {

}

void ScrollableMenu::refresh () {
	for (auto i = 0; i < 5; i++) {
		free_item (items[i]);
	}
	unpost_menu (menu);
  items = (ITEM**) malloc (sizeof (ITEM*) * 5);

	for (auto i = 0; i < 4; i++) {
		items[i] = new_item ("world", "hello");
	}
  items[4] = NULL;

	auto err = set_menu_items (menu, items);
  if (err != E_OK) {
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile << err;
    myfile.close();
    exit (0);
  }

  box (window, 0, 0);	

  post_menu (menu);	
  wrefresh (window); 
}
void ScrollableMenu::nextItem () {
	menu_driver (menu, REQ_DOWN_ITEM);
}

void ScrollableMenu::prevItem () {
	menu_driver (menu, REQ_UP_ITEM);
}

