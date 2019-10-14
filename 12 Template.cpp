/*
Write a function template selection Sort.
Write a program that inputs, sorts and outputs an integer array and a float array.
*/
#include<iostream>
using namespace std;

template<typename T>
void selectionsort(T arr[], int n)
{
    int _min;
    for(int i=0;i<n-1;i++)
    {
        _min=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[_min])
                _min=j;
        }
        if(_min!=i)
            swap(arr[i],arr[_min]);
    }
}

int main()
{
    int a[10],n;
    float b[10];
    cout<<"Enter Number of elements in Integer array: ";
    cin>>n;
    cout<<"\nEnter Elements of Integer array:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    selectionsort(a,n);
    cout<<"\nThe Sorted Array is:  ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n\nEnter number of elements in Float array: ";
    cin>>n;
    cout<<"\nEnter Elements of Float array:\n";
    for(int i=0;i<n;i++)
        cin>>b[i];
    selectionsort(b,n);
    cout<<"\nThe Sorted Array is:  ";
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}
