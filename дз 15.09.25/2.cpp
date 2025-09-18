#include <iostream>
#include <fstream>
using namespace std;
int main (int argc, char* argv[]){
	    if (argc < 3) {
        cout << "в программу не переданы названия файлов которые нужны" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin.is_open()) {
        cout << "файл не открылся" << endl;
        return 2;
    }
        ofstream f(argv[2]);
    if (!f.is_open()) {
        cout << "файл не открылся" << endl;
        return 3;
    }
      string fam, imya, otch;
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

			return 0;
	}
