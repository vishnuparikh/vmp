/*
NINAD DESHPANDE
Roll No: 10
SE Computer II
Batch: S1

Question:

Write a C++ program to create a Calculator for an arithmetic operator (+, -, *, /). The program should take two operands from the user and perform the operation on those two operands depending ypon the operator entered by the user. Use a switch statement to select the operation. Finally, displpay the result.

*/

#include<iostream>

using namespace std;


void noclass()
{
	int p,q;
	float r;
	char cont,opr;

	do
	{
		cout<<"\nEnter Operation to be performed:\n";
		cin>>p>>opr>>q;

		switch(opr)
		{
		case '+':
		r=p+q;
		cout<<"Result: "<<r<<endl;
		break;

		case '-':
		r=p-q;
		cout<<"Result: "<<r<<endl;
		break;

		case '*':
		r=p*q;
		cout<<"Result: "<<r<<endl;
		break;

		case '/':
		r=p/q;
		cout<<"Result: "<<r<<endl;
		break;

		default:
		cout<<"Invalid Function Operator\n";
		break;
		};

		cout<<"Do you want to continue?(Y/N)\n";
		cin>>cont;
	}
	while(cont=='Y'||cont=='y');
}

class maths
{
	int a,b;
	float c;
	public:
	char op;

		void input()
		{
		cout<<"\nEnter the operation to perform:\n";
		cin>>a>>op>>b;
		};

		void add()
		{
		c=a+b;
		cout<<"Result: "<<c<<endl;
		};

		void sub()
		{
		c=a-b;
		cout<<"Result: "<<c<<endl;
		};

		void mul()
		{
		c=a*b;
		cout<<"Result: "<<c<<endl;
		};

		void div()
		{
		c=a/b;
		cout<<"Result: "<<c<<endl;
		};
};

void withclass()
{
	char cont1;
	maths d;

	do
	{
		d.input();
		switch(d.op)
		{
			case '+':
			d.add();
			break;

			case '-':
			d.sub();
			break;

			case '*':
			d.mul();
			break;

			case '/':
			d.div();
			break;

			default:
			cout<<"Invalid Function Operator\n";
			break;
		};
		cout<<"\nDo You Want to Continue?(Y/N)\n";
		cin>>cont1;
	}
	while(cont1=='Y'||cont1=='y');
}

int main()
{
	char s;

	cout<<"Select way of Operation\nUse Class?(Y/N): ";
	cin>>s;

	switch(s)
	{
	case 'Y':
	noclass();
	break;

	case 'N':
	withclass();
	break;

	default:
	cout<<"Invalid Operator\n";
	break;
	};

}


