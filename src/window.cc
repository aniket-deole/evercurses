#include <ncurses.h>

#include "window.h"

Window::Window (unsigned int height, unsigned width,
    unsigned int x, unsigned int y) {

  this->height = height;
  this->width = width;
  this->x = x;
  this->y = y;

  window = newwin (height, width, x, y);
  wborder (window, '|', '|', '-', '-', '+', '+', '+', '+');

  panel = new_panel (window);
  
}

void Window::refresh () {
 
}
