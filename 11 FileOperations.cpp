/*
NINAD DESHPANDE
Roll No.:10
SE COMP II
Batch: S1

Assignment 11

Question:
Write a C++ program that creates an output file, writes information to it,
closes the file and open it again as an input file and read the information from the file.
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    char name[80];
    cout<<"Enter name of file to create\n";
    cin>>name;

    ofstream fout;

    fout.open(name);
    if(!fout)
    {
        cout<<"Error opening file\n";
        exit(1);
    }
    cout<< "Writing to the file" <<endl;
    cout<< "Enter contents for file end with "^D";
    string data;
    while(getline(cin,data))
    {
        if(data == "^D")
            break;
        fout<< data <<endl;
    }
    fout.close();

    ifstream fin;

    fin.open(name);
    if(!fin)
    {
        cout<<"Error opening file\n";
        exit(1);
    }
    cout<< "Reading from the file" <<endl;
    while(fin)
    {
        getline(fin,data);
        cout<< data <<endl;
    }
    fin.close();
    return 0;
}

