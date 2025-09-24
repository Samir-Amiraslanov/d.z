#include <iostream>
using namespace std;
 class myclass{
int* b;
public :
myclass(int c){
	b=new int[c];
	cout<<c<<endl;
}
/*  ~myclass(){
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
