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
        ofstream fout(argv[2]);
    if (!fout.is_open()) {
        cout << "файл не открылся" << endl;
        return 3;
    }
      string fam, imya, otch;
    int a;
    double b;

    while (fin >> fam >> imya >> otch >> a >> b) {
        fout << fam << " " << imya << " " << otch << " " << a << " " << b << "\n";
    }
		if(fin.eof()){cout<<"файл достиг конца  22"<<endl;}
		else {cout<<"произошла ошибка при чтение файла  00"<<endl;}
    return 0;
}
	
