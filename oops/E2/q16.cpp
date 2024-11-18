#include<iostream>
using namespace std;
#include <cmath>

class point{
  double x,y,z;
  public:
    point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}

    double distance(point &p2){
     double d= sqrt(pow(x-p2.x,2)+pow(y-p2.y,2)+pow(z-p2.z,2));
     return d; 
    }
    
};

int main() {
  point p1(1,1,1);
  point p2(2,2,2);
   cout << "The distance between the points is = " << p1.distance(p2);
    
  return 0;

}
