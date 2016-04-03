#include <stdio.h>
#include <ncurses.h>

#include <memory>
#include "ScrollableMenu.h"
#include "window.h"

int main () {
  auto input = 0;
  initscr ();

  if(has_colors() == FALSE) {
    return 0;
  }
  cbreak ();
  noecho ();
  init_pair (1, COLOR_WHITE, COLOR_RED);
  keypad (stdscr,true);

  start_color ();
  refresh ();


  ScrollableMenu sm(10,50,1,1);
  ScrollableMenu sm2(10,50,1,50);
  
  sm.nextPanel (&sm2);

  update_panels ();
  doupdate ();
  ScrollableMenu* activeWindow = &sm;
  while ((char(input) != 'q') && (char(input) != 'Q')) {
    switch (input) {
      case KEY_DOWN:
        activeWindow->nextItem ();
        break;
      case KEY_UP:
        activeWindow->prevItem ();
        break;
      case KEY_RIGHT:
        top_panel ((PANEL*) panel_userptr (sm2.getPanel ()));
        activeWindow = &sm2;
        break;
    }        
    update_panels ();
    doupdate ();
    input = getch ();
  }

  endwin ();
  return 0;
}
