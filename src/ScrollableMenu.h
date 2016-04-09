#ifndef _SCROLLABLE_MENU_H__
#define _SCROLLABLE_MENU_H__

#include <iostream>
#include <curses.h>
#include <menu.h>
#include <panel.h>

#include "window.h"

class ScrollableMenu : public Window{
   public:

    ScrollableMenu (unsigned int, unsigned int, unsigned int,
        unsigned int);
    ~ScrollableMenu ();
    
    void addItem (std::string, std::string);

    void setNextWindow (Window*);
    void setPreviousWindow (Window*);
    void refresh ();

    void onSelect ();
    
    void nextItem ();
    void previousItem ();

 private:
    ITEM** items;
    MENU* menu;


};

#endif
