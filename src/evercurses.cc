#include <cursesapp.h>

class EverCurses : public NCursesApplication
{
public:
  int run () {
    return 0;
  }


};

static EverCurses *Demo = new EverCurses ();
