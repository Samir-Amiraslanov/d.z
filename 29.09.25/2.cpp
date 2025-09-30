#include <iostream>
using namespace std;
class array{
	int size;
	char *p;
public:
	array(int num);
	~array() { delete [] p;}
	char &put(int i);
	char &get(int i);
};
array::array(int num)
{
	p=new char [num];
	if(!p){
		cout<<"ошибка выделения памяти"<<endl;
		exit(1);	
	}
	size=num;	
}
char &array::put(int i)
{
	if(i<0 || i>=size){
		cout << "Ошибка, нарушены границы массива"<<endl;
		exit(1);
}
	return p[i]; 
		
}
char &array::get(int i)
{
	if(i<0 || i>=size){
		cout << "Ошибка, нарушены границы массива"<<endl;
		exit(1);
}
	return p[i]; 
		
}
int main ()
{
	array a(10);
	a.put(3)='X';
	a.put(2)='R';
	cout<<a.get(3)<<a.get(2)<<endl;
	a.put(11)='!';
	return 0;
	
}

/*В put и get используется ссылка (char&) чтобы:
1) Через put(i) можно было присвоить значение элементу массива сразу
2) Через get(i) можно было прочитать элемент массива напрямую, без создания копии
без ссылки, выражение a.put(3) = 'X'; не меняло бы массив, потому что put() вернул бы копию элемента, а не сам элемент */


















