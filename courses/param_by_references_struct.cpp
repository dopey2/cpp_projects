#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

Point returnPointByValue(Point point) {
    return point;
}

Point returnPointByAdress(Point &point) {
    return point;
}


int main() {
    Point point = {1, 2};

    cout << "Adress of pointA:" << &point << endl;
    cout << "_____________" << endl;
    Point retPointByValue = returnPointByValue(point);
    cout << "Adress of retPointByValue:" << &retPointByValue << endl;
    cout << "_____________" << endl;

    return 0;
}
