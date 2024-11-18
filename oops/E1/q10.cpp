#include<iostream>
using namespace std;

int fact(const int &n){
if(n<=1)return 1;
else return n*fact(n-1);}

int main(){
int j=4;
int fc=fact(4);
cout<<"factorial of "<<j<<"is "<<fc;
return 0;}
