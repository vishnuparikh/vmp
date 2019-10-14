/*
Question:
Write C++ program using STL to add binary numbers (assume one bit as one number); use STL stack.
*/
#include<iostream>
#include<stack>
using namespace std;
stack <int> read();
void display(stack<int>&st);
stack <int>add(stack<int>&n1,stack<int>&n2);
int main()
{
    stack<int> n1,n2,n3;
    n1=read();
    n2=read();
    n3=add(n1,n2);
    display(n3);
    return 0;
}
stack<int> read()
{
    char a[40];
    stack<int> st;
    cout<<"Enter a binary number: ";
    cin>>a;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='1')
            st.push(1);
        else
            if(a[i]=='0')
                st.push(0);
    }
    return st;
}
stack<int> add(stack<int>&n1,stack<int>&n2)
{
    stack<int> st;
    int sum,carry=0,bit1,bit2;
    while(!n1.empty() || !n2.empty())
    {
        bit1=bit2=0;
        if(!n1.empty())
        {
            bit1=n1.top();
            n1.pop();
        }
        if(!n2.empty())
        {
            bit2=n2.top();
            n2.pop();
        }
        sum=(bit1+bit2+carry)%2;
        carry=(bit1+bit2+carry)/2;
        st.push(sum);
    }
    if(carry==1)
    st.push(1);
    return st;
}
void display(stack<int>&st)
{
    cout<<"\nAddition of Binary Numbers is: ";
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
