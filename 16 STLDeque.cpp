/*
Write C++ program using STL for Deque (Double ended queue)
*/
#include<iostream>
#include<cstdlib>
#include<list>
#include<iterator>
using namespace std;

class Deque
{
private:
    list<int> lst;
public:
    void eqfront(int a);
    void eqback(int a);
    void dqfront();
    void dqback();
    void display();
};

void Deque::display()
{
    list<int>::iterator st,en;
    st=lst.begin();
    en=lst.end();
    if(st==en)
        cout<<"Queue is Empty\n";
    else
    {
        cout<<"***Queue***\n";
        while(st!=en)
        {
            cout<<*st<<" ";
            st++;
        }
        cout<<'\n';
    }
}

void Deque::dqback()
{
    lst.pop_back();
}

void Deque::dqfront()
{
    lst.pop_front();
}

void Deque::eqback(int a)
{
    lst.push_back(a);
}

void Deque::eqfront(int a)
{
    lst.push_front(a);
}

int main()
{
    int select,a;
    Deque q;
    while(1)
    {
        cout<<"1.Add element at Front\n2.Add element at back\n3.Remove element from front\n4.Remove element from back\n5.Display Queue";
        cout<<"\n\n6.Exit\n";
        cout<<"\nEnter Operation Code: ";
        cin>>select;
        switch(select)
        {
        case 1:
            cout<<"Enter element to enqueue: ";
            cin>>a;
            q.eqfront(a);
            break;
        case 2:
            cout<<"Enter element to enqueue: ";
            cin>>a;
            q.eqback(a);
            break;
        case 3:
            q.dqfront();
            break;
        case 4:
            q.dqback();
            break;
        case 5:
            q.display();
            break;
        case 6:
            exit(0);
        }
        cout<<'\n';
    }
    return 0;
}
