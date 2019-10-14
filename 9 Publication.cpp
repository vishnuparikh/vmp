/*
Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes:
book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data and displays the data members.
If an exception is caught, replace all the data member values with zero values.
*/
#include<iostream>
using namespace std;
class publication
{
public:
    string name;
    float price;
};

class tape: public publication
{
public:
    float minutes;
    tape()
    {
        cout<<"\nEnter Name of the tape:\n";
        cin>>name;
        cout<<"Enter playing time in minutes: ";
        cin>>minutes;
        cout<<"Enter price of tape: ";
        cin>>price;
        try
        {
            if(minutes<=0||price<=0)
                throw 0.00;
        }
        catch(float m)
        {
            cout<<"Invalid Values for Playing time or Pricing.\n";
            name="";
            minutes=0.00;
            price=0.00;
        }
    };
};

class book: public publication
{
public:
    int pages;
    book()
    {
        cout<<"\nEnter Name of Book:\n";
        cin>>name;
        cout<<"Enter number of Pages: ";
        cin>>pages;
        cout<<"Enter price of the book: ";
        cin>>price;
        try
        {
            if(pages<=0||price<=0)
                throw 1;
        }
        catch(int n)
        {
            cout<<"Invalid Values for Page count or Pricing.\n";
            name="";
            pages=0;
            price=0.00;
        }
    };
};

int main()
{
    int n,m;
    cout<<"Enter number of Books and AudioCassettes in the Store: ";
    cin>>n>>m;
    book b[n];
    tape c[m];
    cout<<"\n\n**Record of Books**\n";
    for(int i=0;i<n;i++)
        if(b[i].pages==0)
            cout<<"\nError Entry\n";
        else
        {
            cout<<"\nName: "<<b[i].name<<endl;
            cout<<"Page Count: "<<b[i].pages<<endl;
            cout<<"Price: "<<b[i].price<<endl;
        }
    cout<<"\n\n**Record of AudioCassettes**\n";
    for(int i=0;i<m;i++)
        if(c[i].minutes==0.00)
            cout<<"\nError Entry\n";
        else
        {
            cout<<"\nName: "<<c[i].name<<endl;
            cout<<"Playing time: "<<c[i].minutes<<endl;
            cout<<"Price: "<<c[i].price<<endl;
        }
    return 0;
}
