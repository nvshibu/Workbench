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
	void print() const;
	void input();
	ListElement * getNext() const;
	ListElement * getPrev() const;
	friend class List;
};


class List 
{
	ListElement *start;
	ListElement *end;
public:
	List();
	~List();
	void clear(); // Delete/Free all elements
	void print() const; // output all elements.
	void remove(ListElement *rem); // remove one element
	void add(ListElement *neu, ListElement *whereto=0); // add a new one behind whereto
};


#endif /* LIST_H_ */
