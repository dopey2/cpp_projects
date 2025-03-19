#include <thread>

#include "keyboard.cpp"
#include "log.cpp"

enum GAME_STATUS {
    ONGOING = 0,
    END = 1,
    X_WIN = 2,
    O_WIN = 3
};

const int WINNABLE_INDEXES[8][3] = {
          {0, 1, 2},
          {3, 4, 5},
          {6, 7, 8},
          {0, 3, 6},
          {1, 4, 7},
          {2, 5, 8},
          {2, 4, 6},
          {0, 4, 8},
};

std::string getGameBoard(char boardValues[], int x, int y, char player = 'X') {
    const int index = 3 * y + x;

    std::string boardStr[9] = {};
    for(int i = 0; i < 9; i++) {
        if(index == i) {
            if(boardValues[i] == ' ') {
                boardStr[i] = stringColor(std::string(1, player), FG_GREEN);
            }  else {
                boardStr[i] = stringColor(std::string(1, boardValues[i]), FG_RED);
            }
        } else {
            boardStr[i] = std::string(1, boardValues[i]);
        }
    }

    std::string arrowX0 = x == 0 ? "⇩" : " ";
    std::string arrowX1 = x == 1 ? "⇩" : " ";
    std::string arrowX2 = x == 2 ? "⇩" : " ";
    std::string arrowY0 = y == 0 ? "⇦" : " ";
    std::string arrowY1 = y == 1 ? "⇦" : " ";
    std::string arrowY2 = y == 2 ? "⇦" : " ";

    std::string board = "  " + arrowX0 + "   " + arrowX1 + "   " + arrowX2 + "\n";
    board += "┌───┬───┬───┐\n";
    board += "│ " + boardStr[0] + " │ " + boardStr[1] + " │ " + boardStr[2] + " │" + arrowY0 + "\n";
    board += "├───┼───┼───│\n";
    board += "│ " + boardStr[3] + " │ " + boardStr[4] + " │ " + boardStr[5] + " │" + arrowY1 + "\n";
    board += "├───┼───┼───│\n";
    board += "│ " + boardStr[6] + " │ " + boardStr[7] + " │ " + boardStr[8] + " │" + arrowY2 + "\n";
    board += "└───┴───┴───┘\n";

    return board;
}



class GameController {

private:
  	bool isRunning = false;
    int gameSatus = ONGOING;
    char boardValues[9] = {};
    char player = 'X';
    int xCursor = 0;
    int yCursor = 0;


    void handleKeyboardPress() {
        if(Keyboard::isUpArrowPressed() && this->yCursor > 0) this->yCursor--;
        else if(Keyboard::isDownArrowPressed() && this->yCursor < 2) this->yCursor++;
        else if(Keyboard::isLeftArrowPressed() && this->xCursor > 0) this->xCursor--;
        else if(Keyboard::isRightArrowPressed() && this->xCursor < 2) this->xCursor++;

        if(Keyboard::isEscapePressed()) {
            this->isRunning = false;
        }

        if(Keyboard::isEnterPressed()) {
            int index = this->yCursor * 3 + this->xCursor;
            if(this->boardValues[index] == ' ') {
                this->boardValues[index] = this->player;
                this->player = this->player == 'X' ? 'O' : 'X';
            }
        }


    }

    std::string getGameInfoStr() {
      if(this->gameSatus == ONGOING) {
       return "CURRENT PLAYER: " + std::string(1, this->player)+ "\n";
      }

      if(this->gameSatus == X_WIN) {
        return "X WINS !\n";
      }

      if(this->gameSatus == O_WIN) {
        return "O WINS !\n";
      }

      return "GAME OVER";
    }


    void draw() {
        system("cls");
        std::string gameInfo = this->getGameInfoStr();
        std::string board = getGameBoard(this->boardValues, this->xCursor, this->yCursor, this->player);
        logln(gameInfo);
        logln(board);
    }

    int getGameStatus() {
        for(int i = 0; i < 8; i++) {
          if(
              this->boardValues[WINNABLE_INDEXES[i][0]] != ' ' &&
              this->boardValues[WINNABLE_INDEXES[i][0]] == this->boardValues[WINNABLE_INDEXES[i][1]] &&
              this->boardValues[WINNABLE_INDEXES[i][0]] == this->boardValues[WINNABLE_INDEXES[i][2]]
          ) {
          return boardValues[WINNABLE_INDEXES[i][0]] == 'X' ? X_WIN : O_WIN;
          }
        }

        for(int i = 0; i < 9; i++) {
            if(this->boardValues[i] == ' ') {
                return ONGOING;
            }
        }

        return END;
    }

    void updateGameStatus() {
        this->gameSatus = this->getGameStatus();
    }


public:
    GameController() {
        this->isRunning = true;
        for (uint8_t i = 0; i < 9; i++) {
            boardValues[i] = ' ';
        }
    }

    void run() {
        while(this->isRunning) {
            this->handleKeyboardPress();
            this->updateGameStatus();
            this->draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};