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

    chtype color;

    Window* nextWindow;
    Window* previousWindow;

    virtual void refresh () = 0;
    
    Window* getNextWindow () {
      return nextWindow;
    }
    
    Window* getPreviousWindow (){
      return previousWindow;
    }

    virtual void onSelect () = 0;

    virtual void setNextWindow (Window*) = 0;
    virtual void setPreviousWindow (Window*) = 0;

    PANEL* getPanel () {
      return panel;
    }
};
#endif
