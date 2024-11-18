#include<iostream>
using namespace std;


class Person{
	string name;
	int age,height;
	public:
	Person(string name,int age,int height):name(name),age(age),height(height){}

virtual	void set_details(string x,int y,int z){
		name=x;
		age=y;
		height=z;}

virtual	void printDetails(){
		cout<<"name = "<<name<<endl;
		cout<<"age = "<<age<<endl;
		cout<<"height = "<<height<<" cm"<<endl;}
};
class Student:public Person{
	int roll;
	int yoa;
	public:
	Student(string name,int age,int height,int roll,int yoa):Person(name,age,height),roll(roll),yoa(yoa){} 
	void set_details(string n,int a,int h,int r,int y){
		Person::set_details(n,a,h);
		roll=r;
		yoa=y;}

	void printDetails(){
		Person::printDetails();
		cout<<"Roll no.:"<<roll<<endl;
		cout<<"Year of admission :"<<yoa<<endl;}
};
int main(){
	Person p("Swarnendu",19,181);
	Student s("Swarnendu",19,181,16,2023);
	p.printDetails();
	s.printDetails();
	cout<<"creating array of pointers and printing details:\n";
	Person *arr[4];
	for(int i=0;i<2;i++){
		string n;
		int a;
		int h;
		cout<<"Enter name, age and height: ";
		cin>>n>>a>>h;
		arr[i]=new Person(n,a,h);}
	for(int i=2;i<4;i++){
		string n;
		int h,a,r,y;
		cout<<"Enter name, age, height, roll no. and year of admission :";
		cin>>n>>a>>h>>r>>y;
		arr[i]=new Student(n,a,h,r,y);}
	for(int i=0;i<4;i++)arr[i]->printDetails();
	return 0;} 


