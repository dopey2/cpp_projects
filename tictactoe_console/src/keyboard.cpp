#pragma once

#include <windows.h>

namespace Keyboard {
    static int getLastKeyboardPressCode() {
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                return keyCode;
            }
        }

        return -1;
    }

    bool isEnterPressed() {
        int keyCode = getLastKeyboardPressCode();
        return keyCode == 13;
    }

    bool isEscapePressed() {
        int keyCode = getLastKeyboardPressCode();
        return keyCode == 27;
    }

    bool isLeftArrowPressed() {
        int keyCode = getLastKeyboardPressCode();
        return keyCode == 37;
    }

    bool isUpArrowPressed() {
      int keyCode = getLastKeyboardPressCode();
      return keyCode == 38;
    }

    bool isRightArrowPressed() {
        int keyCode = getLastKeyboardPressCode();
        return keyCode == 39;
    }

    bool isDownArrowPressed() {
        int keyCode = getLastKeyboardPressCode();
        return keyCode == 40;
    }
};