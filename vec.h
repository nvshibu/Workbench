/*
 * vec.h
 *
 *  Created on: 16.05.2022
 *      Author: leth0001
 */

#ifndef VEC_H_
#define VEC_H_


#include <iostream>
using namespace std;

class vec {
	short int dim;
	double *v;
public:
	vec(); // default constructor
	vec(int dim);
	vec(const vec& b); // copy constructor
	~vec(); // destructor
	void input();
	void output() const;
	double abs() const;
	short int getDim() const;
	// Operators:
	vec operator + (const vec& b) const;
	vec operator - (const vec& b) const;

	friend class matrix;
};



#endif /* VEC_H_ */
