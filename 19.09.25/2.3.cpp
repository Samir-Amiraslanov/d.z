#include <iostream>
using namespace std;
int plosh(int a, int b = -1) {
    if (b == -1) return a * a;  
    return a * b;             
}
int main() {
    cout << "Площадь квадрата: " << plosh(5) << endl;    
    cout << "Площадь прямоугольника: " << plosh(5, 4) << endl; 
    return 0;
}
