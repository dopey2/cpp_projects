#include <thread>

#include "GameController.cpp"
#include "keyboard.cpp"
#include "log.cpp"


enum MENU_OPTION {
    MENU_PLAY = 0,
    MENU_QUIT = 1
};

class ConsoleController {

private:
  int menu = MENU_PLAY;
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
          if(this->menu > MENU_PLAY) {
              menu--;
          }
      } else if(Keyboard::isDownArrowPressed()) {
          if(this->menu < MENU_QUIT) {
              menu++;
          }
      }

      if(Keyboard::isEnterPressed()) {
        if(this->menu == MENU_PLAY) {
            this->gameController = new GameController();
        } else if(this->menu == MENU_QUIT) {
            this->isRunning = false;
        }
      }
  }

  void displayMenu() {
      FG_COLOR playColor = this->menu == MENU_PLAY ? FG_MAGENTA : FG_DEFAULT;
      FG_COLOR quitColor = this->menu == MENU_QUIT ? FG_MAGENTA : FG_DEFAULT;

      system("cls");
      std::string playStr = this->gamePlayed > MENU_PLAY ? "Play Again" : "Play";
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
            this->displayMenu();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            this->firstLoopFlag = false;
        }
    }
};