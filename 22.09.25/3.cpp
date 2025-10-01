#include <iostream>
using namespace std;
 class myclass{
int* b;
public :
myclass(int c){
	b=new int[c];
	cout<<c<<endl;
}
<<<<<<< HEAD
 /* ~myclass(){
=======
/*  ~myclass(){
>>>>>>> b946a20b125a88151c6d732128a0736acbd9c69f
   delete b;}*/
 };
int main(){
int i;
for(i=0;i<1000000;i++)
{
	myclass f(i);
	
}
return 0;
}

