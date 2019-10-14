/*
Write C++ program using STL for implementation of stack & queue using SLL
*/
#include<iostream>
#include<cstdlib>
#include<list>
#include<iterator>
using namespace std;

class Queue
{
private:
    list<int> lst;
public:
    void enqueue(int a);
    void dequeue();
    void display();
};

void Queue::display()
{
    list<int>::iterator st,en;
    st=lst.begin();
    en=lst.end();
    if(st==en)
        cout<<"Queue is Empty";
    else
    {
        cout<<"\n**Queue**\n";
        while(st!=en)
        {
            cout<<*st<<' ';
            st++;
        }
    }
}

void Queue::dequeue()
{
    lst.pop_front();
}

void Queue::enqueue(int a)
{
    lst.push_back(a);
}

class Stack
{
private:
    list<int> l;
public:
    void push(int a);
    void pop();
    void display();
};

void Stack::display()
{
    list<int>::iterator st,en;
    st=l.begin();
    en=l.end();
    if(st==en)
        cout<<"Stack is Empty\n";
    else
    {
        cout<<"\n**Stack**\n";
        while(st!=en)
        {
            en--;
            cout<<*en<<'\n';
        }
    }
}

void Stack::pop()
{
    l.pop_back();
}

void Stack::push(int a)
{
    l.push_back(a);
}

int main()
{
    int choice,a;
    Stack s;
    Queue q;
    while(1)
    {
        cout<<"**Stack Operations**\n1.Push Element\n2.Pop Element\n3.Display Stack\n";
        cout<<"**Queue Operations**\n4.Enqueue Element\n5.Dequeue Element\n6.Display Queue\n\n7.Exit";
        cout<<"\n\nEnter Operation Code: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to push: ";
            cin>>a;
            s.push(a);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout<<"Enter element to add to queue: ";
            cin>>a;
            q.enqueue(a);
            break;
        case 5:
            q.dequeue();
            break;
        case 6:
            q.display();
            break;
        default:
            exit(0);
        }
        cout<<"\n\n";
    }
    return 0;
}
