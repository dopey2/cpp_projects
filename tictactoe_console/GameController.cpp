#include <thread>

#include "keyboard.cpp"
#include "log.cpp"

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

    std::string board = "┌───┬───┬───┐\n";
    board += "│ " + boardStr[0] + " │ " + boardStr[1] + " │ " + boardStr[2] + " │\n";
    board += "├───┼───┼───│\n";
    board += "│ " + boardStr[3] + " │ " + boardStr[4] + " │ " + boardStr[5] + " │\n";
    board += "├───┼───┼───│\n";
    board += "│ " + boardStr[6] + " │ " + boardStr[7] + " │ " + boardStr[8] + " │\n";
    board += "└───┴───┴───┘\n";

    return board;
}



class GameController {

private:
    bool isRunning;
    char boardValues[9] = {};
    char player = 'X';
    int xCursor = 0;
    int yCursor = 0;


    void handleKeyboardPress() {
        if(Keyboard::isUpArrowPressed() && this->yCursor > 0) this->yCursor--;
        else if(Keyboard::isDownArrowPressed() && this->yCursor < 2) this->yCursor++;
        else if(Keyboard::isLeftArrowPressed() && this->xCursor > 0) this->xCursor--;
        else if(Keyboard::isRightArrowPressed() && this->xCursor < 2) this->xCursor++;

        if(Keyboard::isEnterPressed()) {
            int index = this->yCursor * 3 + this->xCursor;
            if(this->boardValues[index] == ' ') {
                this->boardValues[index] = this->player;
                this->player = this->player == 'X' ? 'O' : 'X';
            }
        }


    }

    void draw() {
        system("cls");
        std::string board = getGameBoard(this->boardValues, this->xCursor, this->yCursor, this->player);
        logln(board);
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
            this->draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};