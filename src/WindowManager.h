#ifndef __WINDOW_MANAGER_HH_
#define __WINDOW_MANAGER_HH_

#include <vector>

class WindowManager {
  public:
    std::vector <Window*> addWindow ();
    void terminalResized ();
    void hideWindow (std::string);
    void showWindow (std::string);
    void resizeWindow (std::string, int, int, int, int);
};

#endif
