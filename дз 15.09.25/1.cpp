#include <iostream>
#include <fstream>
using namespace std;
int main (){
	
	ifstream fin("text1.txt");
	if(!fin.is_open()){
	cout<<"не открылся"<<endl;
	return 1;
	}
	ofstream f("text2.txt");
	if(!f.is_open()){
		cout<<"не открылся"<<endl;
		return 2;
		}
		string fam,imya,otch;
		int a;
		double b;
		
		if(fin>>fam>>imya>>otch>>a>>b)
		{		
			 char c;
        if (fin >> c) {
            cout << "файл некорректен" << endl;}
             else if (!fin.eof()) {
            cout << "файл некорректен" << endl;} 
			else {f<<fam<<" "<<imya<<" "<<otch<<" "<<a<<" "<<b<<"\n" ;
			}}
		else {cout<<"произошла ошибка при чтение файла"<<endl;}



			return 10;
	}
