#include <thread>

#include "GameController.cpp"
#include "keyboard.cpp"
#include "log.cpp"


class ConsoleController {

private:
  int menu = 0;
  bool isRunning = true;
  GameController* gameController = nullptr;

  void handleKeyboardPress() {
      if(Keyboard::isUpArrowPressed()) {
          if(this->menu > 0) {
              menu--;
          }
      } else if(Keyboard::isDownArrowPressed()) {
          if(this->menu < 1) {
              menu++;
          }
      }

      if(Keyboard::isEnterPressed()) {
        if(this->menu == 0) {
            this->gameController = new GameController();
        } else if(this->menu == 1) {
            this->isRunning = false;
        }
      }
  }

  void draw() {
      FG_COLOR playColor = this->menu == 0 ? FG_MAGENTA : FG_DEFAULT;
      FG_COLOR quitColor = this->menu == 1 ? FG_MAGENTA : FG_DEFAULT;

      system("cls");
      std::cout << this->gameController << std::endl;
      logln(stringColor("1 - Play", playColor));
      logln(stringColor("2 - Quit", quitColor));
  }

public:
    void run() {
        while(this->isRunning) {
            if(this->gameController != nullptr) {
                this->gameController->run();
                return;
            }

            this->handleKeyboardPress();
            this->draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};