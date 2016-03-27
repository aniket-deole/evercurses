#include <curses.h>
#include <cursesapp.h>


class TestApp : public NCursesApplication {

};

int main () {
  printf ("Hello, World!\n");
  return 0;
}
