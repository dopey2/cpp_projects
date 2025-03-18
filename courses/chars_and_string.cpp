#include <iostream>;
using namespace std;


void log(const string text) {
    cout << text << endl;
}

int main() {
    string str = "Hello ";
    log("dsdqsd" + string(1, 'W'));
}