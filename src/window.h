#ifndef _WINDOW_H__
#define _WINDOW_H__
#include <ncurses.h>
#include <panel.h>
class Window {
  public:
    WINDOW* window;
    PANEL* panel; 
    unsigned int height;
    unsigned int width;
    unsigned int x;
    unsigned int y;

    Window (unsigned int, unsigned int, unsigned int, unsigned int);
    ~Window () {}

    void refresh ();
};
#endif
