#include <stdio.h>
#include <ncurses.h>

#include <memory>

#include "window.h"

int main () {
  auto input = 0;
  initscr ();

  if(has_colors() == FALSE) {
    return 0;
  }

  init_pair (1, COLOR_WHITE, COLOR_RED);
  keypad (stdscr,true);

  start_color ();

  refresh ();
  curs_set (0);
  noecho ();

  std::unique_ptr<Window> window (new Window (10, 50, 0, 0));
  while ((char(input) != 'q') && (char(input) != 'Q')) {
    
    window->refresh ();
    
    update_panels ();
    refresh ();
    input = getch ();
  }


  endwin ();
  return 0;
}
