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
	ListElement * getPrev() const;

	/* This virtual function is binded when the pointer used is of type ListElement*  */
	virtual string getValue() const
	{
		if(this->next==NULL)
		{
			return "end";
		}
		else
		{
			return "start";
		}
	}
	
	friend class List;
};


class Data:public ListElement
{
	string value;
public:
	Data(string value);
	string getValue() const; //This function is binded when the pointer used is of type Data*
	
};

class IntData:public ListElement
{
	int value;
public:
	IntData(int value);
	string getValue() const; //This function is binded when the pointer used is of type IntData*
};

class DoubleData:public ListElement
{
	double value;
public:
	DoubleData(double value);
	string getValue() const; //This function is binded when the pointer used is of type IntData*
};





class List 
{
	ListElement *start;
	ListElement *end;
public:
	List();
	//~List();
	//void clear(); // Delete/Free all elements
	void print() const; // output all elements.
	void remove(ListElement *rem); // remove one element
	void add(ListElement *neu, ListElement *where); // add a new one behind whereto
	void addafterhead(ListElement *neu);
	void addbeforetail(ListElement *neu);
	void removelast();
	ListElement* getNode(string value) const;
};




#endif /* LIST_H_ */
