#include<iostream>
using namespace std;

int fact(const int n){
if(n<=1)return 1;
else return n*fact(n-1);}

int main(){
 int n;
 cout<<"enter the number :";
 cin>>n;
 int j=fact(n);
 cout<<"the factorial of the number is "<<j;
return 0;}
