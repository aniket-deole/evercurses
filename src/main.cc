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


  ScrollableMenu* sm = new ScrollableMenu (10,30,0,0, "Notebooks");
  ScrollableMenu* sm2 = new ScrollableMenu (10,30,0,30, "Notes");
  ScrollableMenu* sm3 = new ScrollableMenu (10, 30, 0, 60, "Note Title");
  
  sm->setNextWindow (sm2);
  sm2->setNextWindow (sm3);
  sm3->setNextWindow (sm);

  update_panels ();
  doupdate ();
  Window* activeWindow = sm;
  while ((char(input) != 'q') && (char(input) != 'Q')) {
    switch (input) {
      case KEY_DOWN: {
        ScrollableMenu* smw = dynamic_cast <ScrollableMenu*> (activeWindow);
        smw->nextItem ();
        break;
                     }
      case KEY_UP: {
        ScrollableMenu* smw = dynamic_cast <ScrollableMenu*> (activeWindow);
        smw->previousItem ();
        break;
                   }
      case '\t':
        top_panel ((PANEL*) panel_userptr (activeWindow->getPanel ()));
        activeWindow = activeWindow->getNextWindow ();
        break;
      case '\n':
        activeWindow->onSelect ();
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
