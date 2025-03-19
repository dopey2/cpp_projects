#include <iostream>
using namespace std;


int sum_by_value(int param_a, int param_b) {
    cout << "Value of param_a:" << param_a << endl;
    cout << "Mem adress of param_a:" << &param_a << endl;

    return param_a + param_b;
}

int sum_by_adress(int &param_a, int &param_b) {
    cout << "Value of param_a:" << param_a << endl;
    cout << "Adress of param_a:" << &param_a << endl;

    return param_a + param_b;
}


int main() {
    int val_a = 3;
    int val_b = 4;

    cout << "Value of val_a:" << val_a << endl;
    cout << "Adress of val_a:" << &val_a << endl;

    cout << "_____________" << endl;
    int res_1 = sum_by_adress(val_a, val_b);
    cout << "_____________" << endl;
    int res_2 = sum_by_value(val_a, val_b);

    cout << res_1;
    cout << res_2;
}
