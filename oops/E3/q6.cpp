#include<iostream>
using namespace std;

class Shape2D{
public:
 virtual void  area()=0;
 virtual void  perimeter()=0;
};

class Circle:public Shape2D{
	float r;
	public:
	Circle(float r){
		this->r=r;}
	void area(){
		cout<<"area of circle is :"<<3.14*r*r<<endl;}
	void perimeter(){
		cout<<"perimeter of circle is "<<2*3.14*r<<endl;}
};
class Rectangle:public Shape2D{
	float l,b;
	public:
	Rectangle(float l,float b){
		this->l=l;
		this->b=b;
	}
	void area(){
		cout<<"area of rectangle  is :"<<l*b<<endl;}
	void perimeter(){
		cout<<"perimeter of circle is: "<<2.0*(l+b)<<endl;}
};

int main(){

	Shape2D* ptr[5];
	for(int i=0;i<5;i++){
		if(i<3){
			int r;
			cout<<"enter the radius of circle : ";
			cin>>r;
			ptr[i]=new Circle(r);
		}
		else{
			int l,b;
			cout<<"enter the length and breadth of rectangle : ";
			cin>>l>>b;
			ptr[i]=new Rectangle(l,b);
		}}
		for(int i=0;i<5;i++){
			ptr[i]->perimeter();
			ptr[i]->area();}
		return 0;}


