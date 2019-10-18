/*
Create User defined exception to check the following conditions and throw the exception if the criterion does not meet.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned above.
If any of the condition not met then throw the exception.
*/
#include<iostream>
//#include<cstdlib>
using namespace std;
class applicant
{
public:
    int age, income;
    string city;
    char car;
    applicant()
    {
        cout<<"\n\n**Applicant Details**";
        cout<<"\nEnter Age of applicant: ";
        cin>>age;
        cout<<"Enter Income per month: ";
        cin>>income;
        cout<<"Enter City of Residence: ";
        cin>>city;
        cout<<"Do you own a four wheeler? ";
        cin>>car;
    };
};

int main()
{
    int n;
    cout<<"Enter number of applications: ";
    cin>>n;
    applicant a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n\nProcessing Application Number "<<i+1;
        try
        {
            if(a[i].age<18||a[i].age>55)
                throw '1';
            else if(a[i].income<50000||a[i].income>100000)
                throw '2';
            else if(!(a[i].city=="Pune"||a[i].city=="Mumbai"||a[i].city=="Bangalore"||a[i].city=="Chennai"))
                throw '3';
            else if(a[i].car!='Y')
                throw '4';
            else
                cout<<"\nThe Applicant is cleared for loan application.";
        }
        catch(char m)
        {
            if(m=='1')
            cout<<"\nThe Applicant does not satisfy Vehicle criteria";
            else if(m=='2')
                cout<<"\nThe Applicant does not satisfy the residence criteria.";
            else if(m=='3')
                cout<<"\nThe Applicant does not satisfy income criteria.";
            else if(m=='4')
                cout<<"\nThe Applicant does not satisfy age criteria.";       
        }
    }
    return 0;
}
