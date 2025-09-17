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
		
		while(fin>>fam>>imya>>otch>>a>>b)
		{		
			f<<fam<<" "<<imya<<" "<<otch<<" "<<a<<" "<<b<<"\n" ;
			}
if(fin.eof()){cout<<"файл достиг конца  22"<<endl;}
		else {cout<<"произошла ошибка при чтение файла  "<<endl;}

			return 0;
	}
