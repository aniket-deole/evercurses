#ifndef _WINDOW_H__
#define _WINDOW_H__
#include <ncurses.h>

class Window {
  public:
    WINDOW* window;
    unsigned height;
    unsigned width;

    Window ();
  ~Window () {}
};
#endif
