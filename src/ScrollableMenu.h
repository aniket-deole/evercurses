#ifndef _SCROLLABLE_MENU_H__
#define _SCROLLABLE_MENU_H__

#include <iostream>
#include <curses.h>
#include <menu.h>
#include <panel.h>

class ScrollableMenu {
   public:

    ScrollableMenu (unsigned int, unsigned int, unsigned int,
        unsigned int);
    ~ScrollableMenu ();
    
    void addItem (std::string, std::string);

    void refresh ();
    
    void nextItem ();
    void prevItem ();

    void nextPanel (ScrollableMenu* sm);
    PANEL* getPanel () {
      return panel;
    }

    ScrollableMenu* getNextMenu () {
      return nextMenu;
    }

    void refreshSubsequentItems ();

 private:
    ITEM** items;
    MENU* menu;
    WINDOW* window;

    PANEL* panel;

    chtype color;

    unsigned int height, width, x, y;
  
    ScrollableMenu* nextMenu;

};

#endif
