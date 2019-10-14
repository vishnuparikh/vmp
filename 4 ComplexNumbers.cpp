/*
NINAD DESHPANDE
Roll No: 10
SE Computer II
Batch: S1

Question:

Implement a class Complex which represents a Complex number data type,
Implement the following operations:
1. Constructor(including a default constructor which creates a 0+0i)
2. Overloaded operator + to add two complex numbers.
3. overloaded operator * to multiply two complex numbers.
4. Overloaded << and >> to print and read complex numbers.

*/

#include<iostream>

using namespace std;

class complex
{
	float a,b;

public:
complex()
{
	a=0.00;b=0.00;
};

	complex operator+(complex ob)
	{
	    complex temp;
	    temp.a=a+ob.a;
	    temp.b=b+ob.b;

	    return temp;
	};

	complex operator-(complex ob)
	{
	    complex temp;
	    temp.a=a-ob.a;
	    temp.b=b-ob.b;

	    return temp;
	};

	complex operator*(complex ob)
	{
        complex temp;
        temp.a= (a*ob.a)-(b*ob.b);
        temp.b= (a*ob.b)+(b*ob.a);

        return temp;
	};

	complex operator/(complex ob)
	{
	    complex temp;
        temp.a= (a*ob.a)-(b*(-ob.b));
        temp.b= (a*(-ob.b))+(b*ob.a);
        temp.a=temp.a/((ob.a*ob.a)+(ob.b*ob.b));
        temp.b=temp.b/((ob.a*ob.a)+(ob.b*ob.b));

        return temp;
	};

	friend ostream &operator<<(ostream &out, complex &c);

	friend istream &operator>>(istream &in, complex &c);
};

ostream &operator<<(ostream &out, complex &c)
{
    out<<c.a<<" + i("<<c.b<<")";
    return out;
}

istream &operator>>(istream &in, complex &c)
{
    in>>c.a>>c.b;
    return in;
}

int main()
{
	char out,cont;
	out='N'; cont='N';
	int op;

	complex c1,c2,c3;

	do
	{
	    cout<<"Enter real and imaginary parts of first complex number:\n";
	    cin>>c1;

	    cout<<"Enter real and imaginary parts of second complex number:\n";
	    cin>>c2;

	    do
        {
	    cout<<"\nSelect operation to perform:\n";
	    cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
	    cout<<"Operation Code: ";

	    cin>>op;

	    switch(op)
	    {
        case 1:
            c3= c1+c2;
            cout<<c3<<endl;
            break;

        case 2:
            c3= c1-c2;
            cout<<c3<<endl;
            break;

        case 3:
            c3= c1*c2;
            cout<<c3<<endl;
            break;

        case 4:
            c3=c1/c2;
            cout<<c3<<endl;
            break;
	    }
	    cout<<"Select another operation? (Y/N)\n";
	    cin>>cont;

        }while(cont=='Y' || cont=='y');

        cout<<"Input different complex numbers? (Y/N)\n";
        cin>>out;
	}while(out=='Y' || out=='y');
}
