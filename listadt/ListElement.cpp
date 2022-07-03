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

ListElement* ListElement::getPrev() const
{
	return prev;
}


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
	cout<<"Forward Traversal  ----->\t";

	Data* fitr=(Data*) start; //upcasting ListElement pointer to Data class pointer to access values
	while(fitr!=NULL)
	{
		if(fitr->getValue()=="end") //runtime binding happens altering between ListElement class and Data class
		{
			cout<<fitr->getValue();
		}
		else
		{
			cout<<fitr->getValue()<<"-->";
		}
		fitr=(Data*) fitr->getNext();
	}
	cout<<endl;

	cout<<"Backward Traversal ----->\t";

	Data* itr=(Data*) end;
	while(itr!=NULL)
	{
		if(itr->getValue()=="start")
		{
			cout<<itr->getValue();
		}
		else
		{
			cout<<itr->getValue()<<"<--";
		}
		itr=(Data*) itr->getPrev();
	}
	cout<<endl;

}

ListElement* List::getNode(string value) const
{
	Data* itr=(Data*) start; //upcasting ListElement pointer to Data class pointer to access values
	while(itr!=NULL)
	{
		if(itr->getValue()==value)
		{
			break;
		}
		itr=(Data*) itr->getNext();
	}
	ListElement* where=(ListElement*) itr; //downcasting data class pointer to ListElement type pointer.
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

void List::addafterhead(ListElement* neu)
{
	neu->next = start->next;
	start->next->prev = neu;
	start->next = neu;
	neu->prev = start;
}

void List::addbeforetail(ListElement* neu)
{
	ListElement* itr = start;
	while(itr->next!=NULL)
	{
		itr= itr->next;
	}
	neu->next = itr;
	itr->prev->next = neu;
	neu->prev = itr->prev;
	itr->prev = neu;
}

void List::remove(ListElement *rem)
{
	if(rem->getValue()=="start" || rem->getValue()=="end") //base cass function will be binded in run time if pointer is of type ListElement
	{
		cout<<"Sorry!  Cannot remove head or tail of list"<<endl;
	}
	else
	{
		ListElement* itr = start;
		while(itr!=NULL)
		{
			if(itr==rem)
			{
				itr->prev->next = rem->next;
				itr->next->prev = rem->prev;
				delete itr;
				break;
			}
			itr= itr->next;
		}
	}
}

void List::removelast()
{
	ListElement* itr = start;
	while(itr->next->next!=NULL)
	{
		itr= itr->next;
	}
	itr->prev->next = itr->next;
	itr->next->prev = itr->prev;
	delete itr;
}










