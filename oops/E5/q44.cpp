#include<iostream>
using namespace std;

class ZeroDivide{
	public:
		void disp(){
			cout<<"zero divide"<<endl;
		}
		ZeroDivide(int y=0){
			cout<<y<<"constructed"<<endl;}

};

int divi (int x,int y){
	if(y==0){
		throw ZeroDivide();}
		 return x/y;
	}

int main(){
	int a,b;
	cout<<"enter two no.-->";
	cin>>a>>b;
	try{
		int c=divi(a,b);
		cout<<c;
	}
	catch(ZeroDivide ob){
		ob.disp();}
}

