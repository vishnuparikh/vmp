/*
ASSIGNMENT 03

NINAD M DESHPANDE
Roll No: 10
SE COMPUTER II

Question:

Implement a class CppArray which is identical to a one dimensional C++ array (i.e. the index is a set of consecutive integers starting from 0) except for the following:
1. It performs range check
2. It allows one to be assigned through the use of assignment operator (cp1=cp2)
3. It supports a function that returns the size of the array
4. It allows the reading or printing of the array through the use of cout and cin

*/

#include<iostream>

using namespace std;

class CppArray
{
    int a[50],i,n,t;
    int mem;

public:

    CppArray()
    {
        for(i=0;i<50;i++)
            a[i]=0;
    }

    void getdata();
    void print();
    void sort();
    void range();

    CppArray operator=(CppArray &obj)
    {
        CppArray temp;
        n=obj.n;

        for(i=0;i<n;i++)
            a[i]=obj.a[i];
        return temp;
    };

    void size();

    friend ostream &operator<<(ostream &out, CppArray &cp);
};

ostream &operator<<(ostream &out, CppArray &cp)
{
    int m;

    out<<"EqArray [1]: "<<cp.a[0]<<endl;
    for(m=1;m<cp.n;m++)
        out<<"EqArray ["<<m+1<<"]: "<<cp.a[m]<<endl;
    return out;
}

void CppArray::getdata()
{
    cout<<"Enter the number of elements in the array:\n";
    cin>>n;

    cout<<"Enter the elements of the array:\n";

    for(i=0;i<n;i++)
    cin>>a[i];
}

void CppArray::sort()
{
    int temp;
    temp=0;

    for(t=0;t<n;t++)
        for(i=0;i<n-1;i++)
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
}

void CppArray::print()
{
    cout<<"\nThe sorted array is:\n";

    for(i=0;i<n;i++)
        cout<<"Element "<<i+1<<": "<<a[i]<<endl;
}

void CppArray::range()
{
    cout<<"\nThe range of the array is: "<<a[n-1]-a[0]<<endl;
}

void CppArray::size()
{
    cout<<"\nThe size of the array is: "<<n<<endl;

    mem=n*sizeof(a[0]);
    cout<<"Memory storage of the array is: "<<mem<<" bytes"<<endl;
}

int main()
{
    char out,cont;
    out='N';
    cont='N';
    int op;

    CppArray cp1,cp2;

    do
    {
        cp1.getdata();
        cp1.sort();

        do
        {
            cout<<"\nSelect an operation to perform:\n";
            cout<<"1. Size\n2. Range\n3. Equate\n4. Print\n";
            cout<<"Enter Selection: ";

            cin>>op;

            switch(op)
            {
            case 1:
                cp1.size();
                break;

            case 2:
                cp1.range();
                break;

            case 3:
                cp2=cp1;
                cout<<"The equated array is:\n";
                cout<<cp2;
                break;

            case 4:
                cp1.print();
                break;

            default:
                cout<<"Enter correct operation code\n";
            }

            cout<<"\nDo you want to select another operation?(Y/N): ";
            cin>>cont;
        }while(cont=='Y' || cont=='y');

        cout<<"\nDo you want to try for another array?(Y/N): ";
        cin>>out;
    }while(out=='Y' || out=='y');

    return 0;
}
