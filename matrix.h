/*
 * matrix.h
 *
 *  Created on: 19.06.2022
 *      Author: 
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "vec.h"
#include <iostream>
using namespace std;

class matrix 
{
	short int row;
    short int col;
	vec *vobj;
public:
	matrix(); // default constructor
	matrix(int row,int col);
	matrix(const matrix& b); // copy constructor
	~matrix(); // destructor
	void input();
	void output() const;
	void setVecDim(vec* vob,int d);
	// matrix transpose() const;
	// int* getDim() const;
	// // Operators:
	matrix operator + (const matrix& b) const;
	matrix operator - (const matrix& b) const;
};



#endif /* MATRIX_H_ */
