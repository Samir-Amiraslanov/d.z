#include <iostream>
using namespace std;
class myclass{
	int size ;
	int* mas;
	public:
	myclass(int s){
		size=s;
		mas=new int[size];
		for(int i=0;i<size;i++){
			mas[i]=i;
		} 
	cout<<"v cons 1"<<endl;
	}
	myclass(myclass& noviy){
		size=noviy.size;
		mas=new int[size]; cout<<"v cons kop"<<endl;
		for(int i=0;i<size;i++){
			mas[i]=noviy.mas[i];
		}
	}
	~myclass(){delete[] mas; cout<<"v dis"<<endl; }
	void show() {
        for (int i=0; i<size; i++) cout<<mas[i]<<endl;
		}
};
int main()
{
myclass a(5);   
a.show();   
    myclass b=a;  
      b.show();   

    
    //cout<<"/////////////"<<endl;
   
    
}
