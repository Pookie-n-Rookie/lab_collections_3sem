#include<iostream>
#include<cstring>
using namespace std;
	int main(){
		int arr[]={-1,0,1};
		for(int i=0;i<3;i++){
			int ex=arr[i];
			try{
				if(ex>0){
					throw(ex);}
				else{
					throw "string";
				}
			}
			catch(int x){
				cout<<"integer-"<<x<<endl;}
			catch(const char *s){
				cout<<s<<endl;}
		}
	}


