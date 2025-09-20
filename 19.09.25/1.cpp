#include <iostream>
using namespace std;
class Person {
private:
    string name;   // закрытые переменные
    int age;    
public:
//set функция которая присваивает значение закрытой переменой 
    void setName(string n) { 
        name=n;
    }
    void setAge(int a) {
        age = a;
    }
    //get функция которая возвращает значение закрытой переменой 
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};
int main() {
    Person p;
    // правильно: через set и get
    p.setName("Samir");
    p.setAge(19);
    cout << "Имя: " << p.getName() << endl;
    cout << "Возраст: " << p.getAge() << endl;

/*неправильным будет прямое обращение к закрытыс переменным 
 при компеляции компилятор выдаст ошиьку 
p.name(samir); 
p.age(19); */

    return 0;
}

