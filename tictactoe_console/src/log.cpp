#ifndef _H_LOG_
#define _H_LOG_

#include <iostream>

enum FG_COLOR {
    FG_DEFAULT = 39,
    FG_BLACK = 30,
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_MAGENTA = 35,
    FG_CYAN = 36,
    FG_WHITE = 97,
};

enum BG_COLOR {
    BG_DEFAULT = 49,
    BG_BLACK = 40,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_YELLOW = 43,
    BG_BLUE = 44,
    BG_MAGENTA = 45,
    BG_CYAN = 46,
    BG_WHITE = 107,
};


void logln(std::string text) {
    std::cout << text << std::endl;
}

std::string stringColor(std::string text, FG_COLOR fg_color, BG_COLOR bg_color = BG_DEFAULT) {
    return "\033[0;" + std::to_string(fg_color) + ";" + std::to_string(bg_color) + "m" + text + "\033[0m";
}

#endif