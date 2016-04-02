#ifndef _SCROLLABLE_MENU_H__
#define _SCROLLABLE_MENU_H__


class ScrollableMenu {
   public:

    ScrollableMenu (unsigned int, unsigned int, unsigned int,
        unsigned int);
    void addItem (std::string, std::string);

    void refresh ();
    
 private:
    ITEM** items;
    MENU* menu;

    chtype color;

    unsigned int height, width, x, y;


};

#endif
