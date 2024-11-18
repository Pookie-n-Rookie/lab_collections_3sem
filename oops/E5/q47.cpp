#include<iostream>
using namespace std;

class overflow{
	public:
		overflow(int e=0){
			cout<<"stack is full"<<endl;}
};

class underflow{
	public:
		underflow(int u=0){
			cout<<"stack empty"<<endl;}
};

class stack{
	int *arr;
	int size;
	int top;
	public:
	stack(int s){
		size=s;
		top=-1;
		arr=new int[size];}
	void push(int x){
		if(top==size-1){
			throw overflow(-1);}
		top++;
		arr[top]=x;
	}
	int pop(){
		if(top==-1){
			throw underflow(-1);
		}
		int val=arr[top];
		top-=1;
		return val;}
};

int main(){
	stack ob(5);
	try{
		ob.push(1);
		ob.push(2);
		ob.push(3);
		ob.push(4);
		ob.push(5);
		ob.push(6);
		}
	catch(overflow o){
		cout<<"no more space into stack"<<endl;
	}
	try{
		cout<<ob.pop()<<endl;
		cout<<ob.pop()<<endl;
		cout<<ob.pop()<<endl;
		cout<<ob.pop()<<endl;
		cout<<ob.pop()<<endl;
		cout<<ob.pop();
	}
	catch (underflow u){
		}
}
