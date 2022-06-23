#include "vec.h"
#include "matrix.h"
#include <cmath>
#define NoTEST2

//Default Constructor
matrix::matrix() 
{
	row = 3;
	col = 3;
	short int i;
	short int j;

	vobj = new vec[row];
	if (!vobj) 
	{
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	for(i=0;i<row;i++)
	{
		setVecDim(&vobj[i],col);
	}
}

//Parameterized Constructor
matrix::matrix(int r1, int c1) 
{
	row = r1;
	col = c1;
	short int i;
	short int j;

	vobj = new vec[row];
	if (!vobj) 
	{
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	for(i=0;i<row;i++)
	{
		setVecDim(&vobj[i],col);
	}
}
matrix::matrix(const matrix& b) 
{
	row = b.row;
	col = b.col;
	vobj = new vec[row];
	if (!vobj) {
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	short int i;
	for (i=0; i<row; i++)
	{
		setVecDim(&vobj[i],col);
	}
	#ifdef TEST2
		cout<<"In matrix copy constructor."<<endl;
	#endif
}

//Destructor
matrix::~matrix() 
{
	short int i;
	for(i=0;i<row;i++)
	{
		delete[] vobj[i].v;
	}
	delete[] vobj;
	#ifdef TEST2
		cout<<"In matrix destructor."<<endl;
	#endif
}

/*------------------------I/O-------------------------------------*/
void matrix::setVecDim(vec* vobj,int d)
{
	vobj->dim=d;
	vobj = new vec[d];
	if (!vobj) 
	{
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
}


void matrix::input() 
{
	short int i;
	short int j;
	for (i=0; i<row; i++)
	{
		vobj[i].input();
	}	
}

void matrix::output() const 
{
	short int i;
	short int j;
	for (i=0; i<row; i++)
	{
		vobj[i].output();
		cout<<endl;
	}
}
/*----------------------Calculation----------------------------*/

matrix matrix::operator +(matrix const &b) const 
{
	if(row!=b.row || col!=b.col)
	{
		cout<<"Dimension error in + operation"<<endl;
		abort();
	}
	short int i;
	matrix res(b);
	for (i=0; i<row; i++)
		res.vobj[i] = vobj[i]+b.vobj[i];
	return res;
}

matrix matrix::operator -(matrix const &b) const 
{
	if(row!=b.row || col!=b.col)
	{
		cout<<"Dimension error in - operation"<<endl;
		abort();
	}
	short int i;
	matrix res(b);
	for (i=0; i<row; i++)
		res.vobj[i] = vobj[i]-b.vobj[i];
	return res;
}
