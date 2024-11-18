#include<iostream>
using namespace std;
inline int add(int a,int b,int c){
 return a+b+c;}

int main(){
 int a,b,c;
 cout<<" enter the three integers :";
cin>>a>>b>>c;
cout<<"sum of the integers are :"<<add(a,b,c);
return 0;}

