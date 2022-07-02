/*
 * ListElement.cpp
 *
 *  Created on: 12.12.2019
 *      Author: leth0001
 */

#include "List.h"

ListElement::ListElement()
{
	next = prev = 0;
}

void ListElement::print() const
{
	cout << "An element at address: "<<this<<endl;
}

void ListElement::input()
{
	; // Nothing to do
}

ListElement * ListElement::getNext() const
{
	return next;
}

ListElement * ListElement::getPrev() const
{
	return prev;
}

