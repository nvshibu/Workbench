//============================================================================
// Name        : SSTM1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "ListElement.cpp"
using namespace std;

int main() 
{
	List dataList;

	cout<<"-----Printing the List-----"<<endl;
	dataList.print();
	cout<<endl;

	cout<<"-----Adding new element \"hello\" behind \"start\"-----"<<endl;
	Data* newdata = new Data("hello");
	ListElement* where = dataList.getNode("start");
	if(where==NULL)
	{
		cout<<"Failed to find insertion location"<<endl;
		abort();
	}
	ListElement* neu;
	neu = (ListElement*) newdata;
	dataList.add(neu,where);
	dataList.print();
	cout<<endl;

	cout<<"-----Adding new element \"world\" behind \"hello\"-----"<<endl;
	newdata = new Data("world");
	where = dataList.getNode("hello");
	if(where==NULL)
	{
		cout<<"Failed to find insertion location"<<endl;
		abort();
	}
	neu = (ListElement*) newdata;
	dataList.add(neu,where);
	dataList.print();
	cout<<endl;

	cout<<"-----Adding new element \"virtual\" behind \"hello\"-----"<<endl;
	newdata = new Data("virtual");
	where = dataList.getNode("hello");
	if(where==NULL)
	{
		cout<<"Failed to find insertion location"<<endl;
		abort();
	}
	neu = (ListElement*) newdata;
	dataList.add(neu,where);
	dataList.print();
	cout<<endl;

	cout<<"-----Removing element \"hello\" from the List-----"<<endl;
	ListElement* rem = dataList.getNode("hello");
	if(rem==NULL)
	{
		cout<<"Failed to find element to remove"<<endl;
		abort();
	}
	dataList.remove(rem);
	dataList.print();
	cout<<endl;

	cout<<"-----Removing element \"start\" from the List-----"<<endl;
	rem = dataList.getNode("start");
	if(rem==NULL)
	{
		cout<<"Failed to find element to remove"<<endl;
		abort();
	}
	dataList.remove(rem);
	dataList.print();
	cout<<endl;






	return 0;
}
