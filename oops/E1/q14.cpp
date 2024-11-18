#include<iostream>
using namespace std;
#include<vector>

void print(vector<int>&v){
 for(int i=0;i<v.size();i++){
 cout<<v[i]<<" ";}}

void print(int arr[2][2]){
 for(int i=0;i<2;i++){
  for(int j=0;j<2;j++){
  cout<<arr[i][j]<<" ";}}}

int main(){
 vector<int>v(4,2);
 int arr[2][2]={9,8,7,6};
 print(v);
 cout<<endl;
 print(arr);
return 0;}
 
