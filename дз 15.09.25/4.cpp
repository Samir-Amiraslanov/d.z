#include <iostream>
using namespace std;

int a=100;

int main() {
    int a = 50; 

    cout << "Локальная переменная: " << a << endl;
    cout << "Глобальная переменная: " << ::a << endl; 

    return 0;
}
