#include<iostream>
using namespace std;


class outer{
	int a;
	int b;

	public:
	outer(int x=0,int y=0):a(x),b(y){}
		class divi{
			const char *c;
			public:
			divi(const char *cc="Default message"){
				c=cc;}
			void disp(){
				cout<<"Error: "<<c<<"\n";
			}
		};
		int  division(int x,int y){
			if(y==0) throw divi("division by zero");
			 return x/y;}


};

int main(){
	int a,b;
	cout<<"enter two no. :";
	cin>>a>>b;
	outer ob(a,b);
	try{
		cout<<ob.division(a,b)<<endl;
	}
	catch(outer::divi d){
		d.disp();}
}
