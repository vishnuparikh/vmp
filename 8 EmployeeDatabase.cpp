/*
NINAD DESHPANDE
SE COMP II Roll No: 10

Create employee bio-data using following classes
i) Personal record
ii)Professional record
iii) Academic record
Assume appropriate data members and member function to accept required data & print bio-data.
Create bio-data using multiple inheritance using C++.
*/
#include<iostream>
using namespace std;

class prof
{
    int n;
    string profrec[10];
public:
    void getprof();
    void prof_display();
};

void prof::prof_display()
{
    cout<<"\n--Professional Record--";
    cout<<"\nJob Certifications:";
    for(int i=0;i<n+1;i++)
        cout<<i+1<<". "<<profrec[i]<<endl;
}

void prof::getprof()
{
    cout<<"**Enter Professional Record**";
    cout<<"\nNumber of Job Certifications attained: ";
    cin>>n;
    if(n>0)
    {
        cout<<"List the Job Certifications:\n";
        for(int i=0;i<n+1;i++)
            getline(cin,profrec[i]);
    }
}

class acad
{
    string acadrec,course,edu,blank;
public:
    void getacad();
    void acad_display();
};

void acad::acad_display()
{
    cout<<"\n\n--Academic record--";
    cout<<"\nHighest Education level completed: "<<edu;
    cout<<"\nSpecialization Courses Completed:\n"<<course<<endl;
}

void acad::getacad()
{
    cout<<"**Enter Academic Record**";
    getline(cin,blank);
    cout<<"\nHighest education level completed: ";
    getline(cin,edu);
    cout<<"List out specialization courses completed:\n";
    getline(cin,course);
}

class per
{
private:
    string name;
    int ap_no;
public:
    void getper();
    void per_display();
};

void per::getper()
{
    cout<<"**Enter Personal Details**";
    cout<<"\nEnter Name: ";
    getline(cin,name);
    cout<<"Enter Application number: ";
    cin>>ap_no;
}

void per::per_display()
{
    cout<<"\n--Personal Details--";
    cout<<"\nName: "<<name;
    cout<<"\nApplication Number: "<<ap_no;
}

class employee:public per,public prof,public acad
{
public:
    employee()
    {
        getper();
        getacad();
        getprof();
    }
    void display();
};

void employee::display()
{
    per_display();
    acad_display();
    prof_display();
}

int main()
{
    employee a[5];
    cout<<"\n\n**Employee DataBase:\n";
    for(int j=0;j<5;j++)
    {
        cout<<"\nEmployee Number "<<j+1;
        a[j].display();
    }
}
