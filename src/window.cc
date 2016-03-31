#include <ncurses.h>

#include "window.h"

Window::Window () {
  window = newwin (10, 50, 0, 0);
  wborder (window, '|', '|', '-', '-', '+', '+', '+', '+');
}
