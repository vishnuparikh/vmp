/*
Develop an object oriented program in C++ to create a database of student information system containing the following information:
Name
Roll Number
Class
Division
Date of Birth
Blood group
Contact Address
telephone number
driving licence number
Construct a database with suitable member functions for initializing and destroying the data viz
Constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code, and dynamic memory allocation operators-new and delete
*/

#include<iostream>
using namespace std;

class student
{
	string name,bg,cl;
	int rno,dob[3],tele[10],lic[11];

	public:
	student()
	{

	};
	student(student &s)
	{
		name=s.name;
        bg=s.bg;
		for(int i=0;i<3;i++)
			dob[i]=s.dob[i];
        for(int i=0;i<10;i++)
            tele[i]=s.tele[i];
        for(int i=0;i<11;i++)
			lic[i]=s.lic[i];
		cl=s.cl; rno=s.rno;
	};
	~student()
	{

	};
	void get();
	friend ostream&operator<<(ostream &out, student &s);
};

ostream&operator<<(ostream &out, student &s)
{
	int n;

	out<<"Name:  ";
	out<<s.name<<"\n\n";
	out<<"Class:"<<s.cl<<"  Roll No:"<<s.rno<<endl;
	out<<"Blood Group:  ";
	out<<s.bg;
	out<<"\nDate of Birth:  ";
	for(n=0;n<3;n++)
	{
        out<<s.dob[n];
        if(n<2)
            out<<" / ";
    }
	out<<"\nTelephone Number:\n";
	for(n=0;n<10;n++)
        out<<s.tele[n];
	out<<"\nDriving Licence Number:\n";
	for(n=0;n<11;n++)
        out<<s.lic[n];
	out<<"\n";

	return out;
}

void student::get()
{
	cout<<"Enter Your Name: ";
		getline(cin,name);

	cout<<"Class and Roll Number:\n";
	cin>>cl>>rno;

	cout<<"Blood Group: ";
	cin>>bg;

    cout<<"Date of Birth (dd mm yy): ";
	cin>>dob[0]>>dob[1]>>dob[2];

	cout<<"Telephone Number: ";
	for(int i=0;i<10;i++)
		cin>>tele[i];

	cout<<"Driving Licence number: ";
	for(int i=0;i<11;i++)
		cin>>lic[i];
}

int main()
{
	//int n=0;
	student s;
		s.get();
	student scopy(s);
	cout<<"\nCopy Constructor Output:\n\n";
	cout<<scopy;
}
