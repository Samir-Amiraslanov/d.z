#include <iostream>
using namespace std;

class myclass1 {
public:
   myclass1() { cout << "Конструктор myclass1\n"; }
};

class myclass2 {
    myclass1 e; 
public:
    myclass2() { cout << "Конструктор myclass2\n"; }
};

int main() {
   myclass2 c; 
    return 0;
}
