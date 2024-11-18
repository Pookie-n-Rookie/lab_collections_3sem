#include<iostream>
using namespace std;

void swap(int &a,int &b){
 int t=a;
 a=b;
b= t;}
  int main(){
  int a=2,b=3;
  cout<<"before swapping :"<<"a ="<<a<<" and b="<<b;
  swap(a,b);
  cout<<"after swapping:"<<"a ="<<a<<" and b="<<b;
return 0;} 
