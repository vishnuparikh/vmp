/*
A book shop maintains the inventory of books that are being sold at the shop. The
list
includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system searches
the list and displays whether it is available or not. If it is not, an
appropriate message is
displayed. If it is, then the system displays the book details and requests for the number of
copies required. If the requested copies book details and requests for the number of copies
required. If the requested copies are available
, the total cost of the requested copies is
displayed; otherwise the message ―Required copies not in stock‖ is displayed.
Design a
system using a class called books with suitable member functions and Constructors. Use
new operator in constructors to alloca
te memory space required. Implement C++ program
for the system.
*/

#include<iostream>
//#include<string.h>
using namespace std;

class books
{
private:
	string _author,_pub;
	float price;
	int stock;
public:
	string _name;
	books(string name, string author, string pub, float p, int st):_name(name),_author(author),_pub(pub),price(p),stock(st)
	{};
	books()
	{
        _name="N/A";
        _author="N/A";
        _pub="N/A";
        price=0;  stock=0;
	};
	void confirm();
	friend ostream&operator<<(ostream &out, books &b);
};

void books::confirm()
{
    char confirmation,b_all,go='N';
    int q;
    do
    {
        cout<<"\nEnter Quantity of Purchase: ";
        cin>>q;
        if(q<=stock)
            break;
        else
        {
            cout<<"\nEnough Stock is not Available.\nBuy all available?(Y/N): ";
            cin>>b_all;
        }
        if(b_all=='y'||b_all=='Y')
            {
                q=stock;
                break;
            }
        else
            go='Y';
    }while(go=='Y');
    cout<<"\nTotal cost of Purchase "<<q*price;
    cout<<"\nConfirm Purchase(Y/N): ";
    cin>>confirmation;
    if(confirmation=='Y'||confirmation=='y')
    {
        stock-=q;
        cout<<"\nThank You for ordering.";
    }
}

ostream &operator<<(ostream &out, books &b)
{
	out<<"\nName: "<<b._name<<"\nAuthor: "<<b._author<<"\nPublication: "<<b._pub<<"\nPrice: "<<b.price<<"\nStock: "<<b.stock<<"\n";
	return out;
}

int main()
{
    int i;
    string title;
    char go;
	bool avail;
	books b[5]={books("A Man Called Carver","Veena Gavankar","nbt.india",110,5),books("Everything is Fucked","Mark Manson","HarperCollins",499,5),books("The Revolution","OSHO","JAICO",250,5)};
    do
    {
        go='N';
        cout<<"\nList of Available Books:\n";
        for(i=0;i<5;i++)
            if(b[i]._name!="N/A")
            cout<<b[i];
        cout<<"\nEnter title of book to order: \n";
        getline(cin,title);
        for(i=0;i<5;i++)
            if(title==b[i]._name)
            {
                cout<<"\nDescription of Book:"<<b[i];
                avail=true;
                break;
            }
        if(avail==false)
        {
            cout<<"\nEnter valid Title";
            go='Y';
        }
        else
            b[i].confirm();
        cout<<"\nBuy another Book?(Y/N): ";
        cin>>go;
    }while(go=='Y'||go=='y');
    return 0;
}

