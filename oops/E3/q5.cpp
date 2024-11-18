#include<bits/stdc++.h>
using namespace std;
class Employee
{
	string name ;
	double salary;
	public :
	void setName (string name )
	{
		this->name = name ;
	}
	void setSalary ( double salary)
	{
		this->salary = salary ;
	}
	Employee(string name, double salary)
	{
		setName(name);
		setSalary(salary);
	}

	virtual void printDetails()
	{
		cout<<" Name of employee : "<<name<<endl;
		cout<<" Salary : " <<salary<<endl;
	}
};


class Manager : public Employee
{
	int type ; double allowance ;
	public:
	Manager(int t , double a) : Employee("",0.0)
	{
		this->type = t;
		this->allowance = a;
	}

	void printDetails(){
		Employee::printDetails();
		cout<<"TYPE: "<<endl;
		cout<<"Allowance: "<<endl;}


};
	class Clerk : public Employee
	{

		int type ; double allowance ;
		public:
		Clerk(int t, double a):Employee("",0.0)
		{
			this->type = t;
			this->allowance = a;
		}
		void printDetails()
		{
			Employee::printDetails();
			cout<<" TYPE : "<<type<<endl;
			cout<<" Allowance : "<<allowance<<endl;

		}

	};



	int main()
	{

		Employee* e[2];

		for(int i=0;i<2;i++)
		{
			cout<<" enter name salary type allowance for Clerk "<<i+1<<endl;
			string name; double sal,all;int t;
			cin>>name>>sal>>t>>all;

			e[i] = new Clerk(t,all);
			e[i]->setName(name);
			e[i]->setSalary(sal);
			e[i]->printDetails();
                        delete e[i];}
			for(int i =0 ;i<2;i++)
			{
				cout<<"enter name salary type allowance for Manager "<<i+1<<endl;
				string name ; double sal,all;int t;
				cin>>name>>sal>>t>>all;

				e[i]=new Manager(t,all);
				e[i]->setName(name);
				e[i]->setSalary(sal);

				e[i]->printDetails();
			}


			return 0;
		}
