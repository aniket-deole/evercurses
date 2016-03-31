#include <stdio.h>
#include <ncurses.h>

WINDOW* window;

int main () {
  int input;
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

  window = newwin (50, 50, 0, 0);
  while ((char(input) != 'q') && (char(input) != 'Q')) {
    
    window = newwin (50,50,0,0);
    
    wborder (window, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(window, 3, 1, "%s", "File");
    refresh ();
    wrefresh (window);
    input = getch ();
  }


  endwin ();
  return 0;
}
