#include<iostream>
using namespace std;
#include <cmath>

class rectangle{
  double l,b;
  public:
    rectangle(double l=0,double b=0):l(l),b(b){}

    void area(rectangle &p){
     cout<<"The area of rectangle whose length is "<<p.l<<" breadth is "<<p.b<<" is "<<p.l*p.b<<"\n";
    }
    
};

int main() {
  rectangle p1(1,1);
  rectangle p2(2,2);
  rectangle p3(3,4);
  rectangle p4(5,6);
  p1.area(p1);
  p2.area(p2);
  p3.area(p3);
  p4.area(p4);
    
  return 0;

}
