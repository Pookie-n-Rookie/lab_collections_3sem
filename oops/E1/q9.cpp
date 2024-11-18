#include<iostream>
using namespace std;
#include<cstring>
void swap(char*c,char*d){
char temp[100];
strcpy(temp,c);
strcpy(c,d);
strcpy(d,temp);}

int main(){
char arr1[100],arr2[100];
cout<< "enter the two strings :";
cin>>arr1>>arr2;
swap(arr1,arr2);
cout<<"after swaping the strings are :"<<arr1<<" and "<<arr2;
return 0;}
