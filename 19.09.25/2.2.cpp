#include <iostream>
using namespace std;
int umnoj(int a, int b) {
    return a * b;
}
int umnoj(int a, int b, int c) {
    return a * b * c;
}
int main() {
    cout << umnoj(2, 3) << endl;
    cout << umnoj(2, 3, 4) << endl;    
    return 0;
}
