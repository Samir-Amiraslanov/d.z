#include <iostream>
using namespace std;

class truck;

class car{
	
	int passeger, speed;

 public:
 car(int p, int s) : passeger(p), speed(s) {}
 
 friend int sp_greater(car c, truck t);
 
};

class truck {
	
 int weight, speed;
 	
 public:
 truck(int w, int s) : weight(w), speed(s) {}
 
 friend int sp_greater(car c, truck t);
 		
};

int sp_greater(car c, truck t) {
 return c.speed-t.speed;
}

int main()
{
 int t;
 car c1(4,70), c2(5,60);
 truck t1(1000,0), t2(5000,70);
 t=sp_greater(c1, t1);
 if(t<0) cout<<"Грузовик быстрее"<<endl;
	else if(t==0) cout<<"Скорость машин равны"<<endl;
	  else cout<<"Легковая машина быстрее"<<endl;
	  
 t=sp_greater(c2, t2);	
 if(t<0) cout<<"Грузовик быстрее"<<endl;
	else if(t==0) cout<<"Скорость машин равны"<<endl;
	  else cout<<"Легковая машина быстрее"<<endl;
 return 0;  
}
