#include<bits/stdc++.h>
using namespace std;


class point{
int x,y;
public:
point(int x=0,int y=0){
 this->x=x;
 this->y=y;
 }

double  operator-(point&ob){
point t;
t.x=x-ob.x;
t.y=y-ob.y;
double dist=sqrt(t.x*t.x+t.y*t.y);
return dist;}
void disp(){
cout<<"x= "<<x;
cout<<"y= "<<y<<endl;}
};

int main(){
int x1,y1,x2,y2;
cout<<"enter the points :";
cin>>x1>>y1;
cout<<"enter the 2nd points :";
cin>>x2>>y2;
point obj1(x1,y1),obj2(x2,y2);
cout<<"distance between those points :"<<obj1-obj2<<endl;
return 0;}



