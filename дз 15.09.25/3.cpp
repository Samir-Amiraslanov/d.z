#include <iostream>
using namespace std;
namespace sloj {
    int add(int a, int b) {
        return a + b;
    }
}
namespace razn {
    int add(int a, int b) {
        return a - b;
    }
}
int main() {
    int x = 3, y = 5;
    cout << "сумма: " << sloj::add(x, y) << endl;
    cout << "разность: " <<razn::add(x, y) << endl;

    return 0;
}
