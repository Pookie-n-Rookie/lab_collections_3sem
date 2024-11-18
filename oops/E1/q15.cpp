#include<iostream>
using namespace std;

inline void add(int x,int y=0,int z=0){
  cout<< x+y+z<<endl;}

int main(){
  add(3,2,4);
  add(2,1);
  add(2);
 return 0;}
