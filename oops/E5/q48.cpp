#include<iostream>
using namespace std;

class motor{
    int tr;
    public:
    motor(int z=0){
      tr=z;
      if(!tr) throw "Working";
      else throw "Not working";
    }

};

class car{
 motor*v;
  public:
  car(int z=0){
    try{
      v=new motor(z);
    }
    catch(const char*ch){
      throw ;
    }

  }

};


class garage{
  public:
  garage(int f=0){
    try{
      car ct(f);
    }
    catch(const char *s){
      cout<<"the motor of the car is-->"<<s<<endl;
      if(s=="Not working")throw "NEED to  repair";
      else throw "No need to repair";
    }
  }
};

int main(){
  int arr[]={1,0};
  for(int i=0;i<2;i++){
    try{
      cout<<"for "<<i+1<<" car ";
      garage g(arr[i]);
    }
    catch(const char *s){
      cout<<s<<endl;
    }
  }}
