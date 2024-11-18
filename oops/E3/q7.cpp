#include<bits/stdc++.h>
using namespace std;
class shape{
	public:
		virtual void area()=0;
		virtual void volume()=0;
};
class twodshape:public shape{
	public:
		void area(){
			cout<<"2D";
		}
};
class threedshape:public shape{
	public:
		void area(){
			cout<<"3D";}
		};
		class circle:public twodshape{
			int r;
			public:
			circle(float r){
				this->r=r;
			}
			void area(){
				cout<<"It is a circle with area :"<<3.14*r*r<<endl;}
			void volume(){
				return; }
		};
		class triangle:public twodshape{
			float l,b;
			public:
			triangle(float l,float b){
				this->l=l;
				this->b=b;

			}

			void area(){
				cout<<"It is a triangle with area :"<<0.5*l*b<<endl;}
			void volume(){return ;}
		};
		class ellipse:public twodshape{
			float l,b;
			public:
			ellipse(float l,float b){
				this->l=l;
				this->b=b;
			}

			void area(){
				cout<<"It is an ellipse with area :"<<3.14*l*b<<endl;}
			void volume(){return ;}
		};
		class sphere:public threedshape{
			float r;
			public:
			sphere(float r){
				this->r=r;
			}

			void area(){
				cout<<"It is a sphere  with surface area :"<<4*3.14*r*r<<endl;}
			void volume(){
				cout<<" its volume is :"<<4/3*3.14*r*r*r<<endl;}
		};
		class cube:public threedshape{
			float a;
			public:
			cube(float a){
				this->a=a;
			}

			void area(){
				cout<<"It is a cube  with surface area :"<<6*a*a<<endl;}
			void volume(){
				cout<<" its volume is :"<<a*a*a<<endl;}
		};

		int main(){


			vector<shape*>ptr;
			int i=0;
			while(1){
				cout<<" choose 1.circle 2.triangle 3.ellipse 4.cube 5.sphere 6.exit "<<endl;
				int  t;
				cin>>t;
				if(t==1){
					cout<<"enter the radius of circle :";
					float r;
					cin>>r;
					ptr.push_back(new circle(r));
					ptr[i]->area();
				}
				if(t==2){
					cout<<"enter the length and breadth of rectangle :";
					float l,b;
					cin>>l>>b;
					ptr.push_back(new triangle(l,b));
					ptr[i]->area();
				}
				if(t==3){
					cout<<"enter the major  and minor axis's lengths :";
					float b,h;
					cin>>b>>h;
					ptr.push_back(new ellipse(b,h));
					ptr[i]->area();
				}
				if(t==4){
					cout<<"enter the side of cube :";
					int r;
					cin>>r;
					ptr.push_back(new cube(r));
					ptr[i]->area();
					ptr[i]->volume();
				}
				if(t==5){
					cout<<"enter the radius of sphere:";
					int r;
					cin>>r;
					ptr.push_back(new sphere(r));
					ptr[i]->area();
					ptr[i]->volume();
				}
				if(t==6)break;
				i++;}
			return 0;}



