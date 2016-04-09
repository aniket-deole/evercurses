#include <iostream>

#include "window.h"

void Window::printInMiddle (std::string str) {
	auto temp = (width - str.length ())/ 2;
	auto tempx = x + (int)temp;
	wattron(window, color);
	mvwprintw(window, 1, tempx, "%s",  str.c_str ());
	wattroff(window, color);
	wrefresh(window);
}
