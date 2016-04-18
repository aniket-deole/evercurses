#include <stdio.h>
#include <ncurses.h>

#include <memory>
#include "ScrollableMenu.h"
#include "window.h"

ScrollableMenu* sm, *sm2, *sm3;

void initWindows () {
 
  int fullWindowX, fullWindowY;

  getmaxyx (stdscr, fullWindowY, fullWindowX);
 
  if (fullWindowX > 80) {
    sm = new ScrollableMenu (fullWindowY, (int) (fullWindowX * 0.2), 0, 0, "Notebooks");  
    sm2 = new ScrollableMenu (fullWindowY,(int) (fullWindowX * 0.2),0, 
        (int) (fullWindowX * 0.2) - 1, "Notes");
    sm3 = new ScrollableMenu (fullWindowY, (int)(fullWindowX * 0.6) + 3, 0, 
        (int) (fullWindowX * 0.4) - 2, "Note Title");
  } else {
    endwin ();
    printf ("%d %d\n", fullWindowX, fullWindowY);
    exit (0);
  }


  return;
}

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

  initWindows ();
 
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
