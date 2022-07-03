/*
 * List.h
 *
 *  Created on: 30.05.22
 *      Author: SSTM1
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;


class ListElement 
{
	ListElement *next;
	ListElement *prev;
public:
	ListElement();
	// void input();
	ListElement* getNext() const;
	// ListElement * getPrev() const;
	friend class List;
};


class Data:public ListElement
{
	string value;
public:
	Data(string value);
	string getValue() const;
	//virtual add(ListElement *neu, ListElement *where)
};

class List 
{
	Data *start;
	Data *end;
public:
	List();
	//~List();
	//void clear(); // Delete/Free all elements
	void print() const; // output all elements.
	//void remove(ListElement *rem); // remove one element
	void add(ListElement *neu, ListElement *where); // add a new one behind whereto
	ListElement* getNode(string value) const;
};


#endif /* LIST_H_ */
