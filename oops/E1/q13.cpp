#include<iostream>
using namespace std;
int maxm(int a,int b,int c){
  if(a>b && a>c)return a;
  else if(b>c) return b;
  else return c;}

int maxm (int arr[],int n){
  int maxmi=arr[0];
  for(int i=1;i<n;i++){
  if(arr[i]>maxmi)maxmi=arr[i];}
  return maxmi;}

int main(){
  int a=2,b=3,c=6;
  int arr[]={1,2,3,4,5};
  cout<<"maxm when three numbers :"<<maxm(a,b,c)<<" maxm when the integer array is passed :"<<maxm(arr,5);
return 0;}
