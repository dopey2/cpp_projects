#include <thread>

#include "GameController.cpp"
#include "keyboard.cpp"
#include "log.cpp"


class ConsoleController {

private:
  int menu = 0;
  int gamePlayed = 0;
  bool isRunning = true;
  bool firstLoopFlag = true;
  GameController* gameController = nullptr;

  void handleKeyboardPress() {
      if(this->firstLoopFlag) {
          // skip the first loop to ignore the enter key from the program launch;
          return;
      }

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
      std::string playStr = this->gamePlayed > 0 ? "Play Again" : "Play";
      logln(stringColor("1 - " + playStr, playColor));
      logln(stringColor("2 - Quit", quitColor));
  }

public:
    ConsoleController() {
         delete this->gameController;
         this->gameController = nullptr;
    }

    void run() {
        while(this->isRunning) {
            if(this->gameController != nullptr) {
                this->gameController->run();
                delete this->gameController;
                this->gameController = nullptr;
                this->gamePlayed++;
            }

            this->handleKeyboardPress();
            this->draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            this->firstLoopFlag = false;
        }
    }
};