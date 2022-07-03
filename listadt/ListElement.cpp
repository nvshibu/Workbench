/*
 * ListElement.cpp
 *
 *  Created on: 12.12.2019
 *      Author: leth0001
 */

#include "List.h"


/*-----------------------ListElement------------------------*/
ListElement::ListElement()
{
	next = prev = 0;
}

// void ListElement::print() const
// {
// 	cout << "An element at address: "<<this<<endl;
// }

// void ListElement::input()
// {
// 	; // Nothing to do
// }

ListElement* ListElement::getNext() const
{
 	return next;
}

// ListElement* ListElement::getPrev() const
// {
// 	return prev;
// }


/*-----------------------------------------DataList-------------------------------------*/

Data::Data(string value)
{
	this->value=value;
}

string Data::getValue() const
{
	return value;
}



/*--------------------------------------------List-----------------------------------*/

List::List()
{
	start = new ListElement();
	end = new ListElement();
	start->next = end;
	start->prev = NULL;
	end->next = NULL;
	end->prev = start;
}
void List::print() const
{
	Data* itr=(Data*) start;
	cout<<"The elements in the List are"<<endl;
	while(itr!=NULL)
	{
		if(itr->getValue()=="end")
		{
			cout<<itr->getValue();
		}
		else
		{
			cout<<itr->getValue()<<"-->";
		}
		itr=(Data*) itr->getNext();
	}
	cout<<endl;
}

ListElement* List::getNode(string value) const
{
	Data* itr=(Data*) start;
	while(itr!=NULL)
	{
		if(itr->getValue()==value)
		{
			return itr;
		}
		itr=(Data*) itr->getNext();
	}
	ListElement* where=(ListElement*) itr;
	return where;
}

void List::add(ListElement* neu,ListElement* where)
{
	ListElement* itr = start;
	while(itr!=NULL)
	{
		if(itr==where)
		{
			neu->next=itr->next;
			neu->prev=itr;
			itr->next->prev=neu;
			itr->next=neu;
			break;
		}
		itr= itr->next;
	}
}









