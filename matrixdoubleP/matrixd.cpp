#include "vec.h"
#include "matrixd.h"
#include <cmath>
#define NoTEST2

//Default Constructor
matrix::matrix() //default constructor for 3 rows and 3 columns
{
	row = 3;
	col = 3;
	short int i;
	short int j;

	vobj = new vec*[row];//creating an array of vector pointers
	if (!vobj) 
	{
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	for(i=0;i<row;i++)
	{
		vobj[i]=new vec(col);//Each pointer in array pointing to vector object
	}
}

//Parameterized Constructor
matrix::matrix(int r1, int c1) 
{
	row = r1;
	col = c1;
	short int i;
	short int j;

	vobj = new vec*[row];//creating an array of vector pointers
	if (!vobj) 
	{
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	for(i=0;i<row;i++)
	{
		vobj[i]=new vec(col);//Each pointer in array pointing to vector object
	}
	setVecDim(&obj3,col); //setting the no of columns of vector object to value of col
}
matrix::matrix(const matrix& b) //copy constructor definition is not used in this program
{
	row = b.row;
	col = b.col;
	vobj = new vec*[row];
	if (!vobj) {
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	short int i;
	for (i=0; i<row; i++)
	{
		vobj[i]=new vec(col);
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
		delete[] vobj[i];//deleting each pointer in array of vector pointers
	}
	delete[] vobj;
	#ifdef TEST2
		cout<<"In matrix destructor."<<endl;
	#endif
}

/*------------------------I/O-------------------------------------*/
void matrix::setVecDim(vec* vobj,int d) //for setting no of columns in obj3
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
		vobj[i]->input(); //array pointer calling member function
	}	
}

void matrix::output() const 
{
	short int i;
	short int j;
	for (i=0; i<row; i++)
	{
		vobj[i]->output();
		cout<<endl;
	}
}
/*----------------------Calculation----------------------------*/

matrix matrix::operator +(matrix const& b) const 
{
	if(row!=b.row || col!=b.col)
	{
		cout<<"Dimension error in + operation"<<endl;
		abort();
	}
	short int i;
	matrix res(b.row,b.col);
	for (i=0; i<row; i++)
	{
		vec* obj1=vobj[i];
		vec* obj2=b.vobj[i];
		res.obj3 = (*obj1)+(*obj2); //using pointer to objects and storing result in obj3
		res.vobj[i]=&res.obj3; //obj3 is a member of matrix class. So will not get destroyed
	}
	return res;
}

matrix matrix::operator -(matrix const& b) const 
{
	if(row!=b.row || col!=b.col)
	{
		cout<<"Dimension error in - operation"<<endl;
		abort();
	}
	short int i;
	matrix res(b.row,b.col);
	for (i=0; i<row; i++)
	{
		vec* obj1=vobj[i];
		vec* obj2=b.vobj[i];
		res.obj3 = (*obj1)-(*obj2);
		res.vobj[i]=&res.obj3;
	}
	return res;
}
