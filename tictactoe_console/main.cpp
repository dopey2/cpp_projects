#include "ConsoleController.cpp"

int main() {
  SetConsoleOutputCP(65001);
  ConsoleController consoleController;
  consoleController.run();
  return 0;
}