#include<iostream>
using namespace std;

class B{
public:
B(){
cout<<"B const";
}
virtual ~B(){
cout<<"B dest ";}};

class c:public B{
public:
c(){
cout<<"c const";}

~c(){
cout<<" c dest";}
};
int main(){
B* ptr=new c();
delete(ptr);}
