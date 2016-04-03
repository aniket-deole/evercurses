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


  ScrollableMenu sm(10,30,1,1);
  ScrollableMenu sm2(10,30,1,30);
  ScrollableMenu sm3 (10, 30, 1, 60);
  
  sm.nextPanel (&sm2);
  sm2.nextPanel (&sm3);
  sm3.nextPanel (&sm);

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
      case '\t':
        top_panel ((PANEL*) panel_userptr (activeWindow->getPanel ()));
        activeWindow = activeWindow->getNextMenu ();
        break;
      case '\n':
        activeWindow->refreshSubsequentItems ();
        break;
    }        
    update_panels ();
    doupdate ();
    refresh ();
    input = getch ();
  }

  endwin ();
  return 0;
}
