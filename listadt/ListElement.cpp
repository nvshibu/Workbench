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

/*--------------------------------------------List-----------------------------------*/

List::List()
{
	start = new Data("start");
	end = new Data("end");
	start->next = end;
	start->prev = NULL;
	end->next = NULL;
	end->prev = start;
}
void List::print() const
{
	Data* itr=start;
	cout<<"The elements in the List are"<<endl;
	while(itr!=NULL)
	{
		cout<<itr->getValue()<<"-->";
		itr=(Data*) itr->getNext();
	}
	cout<<endl;

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







