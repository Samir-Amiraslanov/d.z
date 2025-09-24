#include <iostream>
using namespace std;

class myclass {
    int x, y;
public:
    myclass(int a,int b) : x(a), y(b) {}
    void print() { cout <<"x="<<x<<" y="<<y<<endl; }
};

int main() {
    myclass p(3,7);
    p.print();
    return 0;
}
