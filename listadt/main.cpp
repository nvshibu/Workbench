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

	/*----------Printing the List--------------------*/
	dataList.print();
	cout<<endl;

	/*---------------Addition new element "hello" in the List-------------------*/
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
	cout<<"After Addition of new Element "<<endl;
	dataList.print();
	cout<<endl;

/*---------------Addition new element "world" in the List-------------------*/
	newdata = new Data("world");
	where = dataList.getNode("hello");
	if(where==NULL)
	{
		cout<<"Failed to find insertion location"<<endl;
		abort();
	}
	neu = (ListElement*) newdata;
	dataList.add(neu,where);
	cout<<"After Addition of new Element "<<endl;
	dataList.print();
	cout<<endl;

/*---------------Addition new element "virtual" in the List-------------------*/
	newdata = new Data("virtual");
	where = dataList.getNode("hello");
	if(where==NULL)
	{
		cout<<"Failed to find insertion location"<<endl;
		abort();
	}
	neu = (ListElement*) newdata;
	dataList.add(neu,where);
	cout<<"After Addition of new Element "<<endl;
	dataList.print();
	cout<<endl;

/*---------------Removing element "hello" from the List-------------------*/
	ListElement* rem = dataList.getNode("hello");
	if(rem==NULL)
	{
		cout<<"Failed to find element to remove"<<endl;
		abort();
	}
	dataList.remove(rem);
	cout<<"After Removal of Element \"hello\" "<<endl;
	dataList.print();
	cout<<endl;






	return 0;
}
