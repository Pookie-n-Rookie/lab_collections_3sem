#include<iostream>
using namespace std;

double conversion(int  c){
 return 9*c/5.0+32.0;}

int main(){
  for(int i=0;i<=100;i++){
  cout<<i<< " celcius is :"<<conversion(i)<<" Fahrenheit"<<endl;}
return 0;}

