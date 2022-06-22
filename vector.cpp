#include "vec.h"
#include <cmath>
#define NOTEST

short int vec::getDim() const
{ return dim; }

vec::vec() {
	dim = 3;
	v = new double[dim];
	if (!v) {
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	short int i;
	for(i=0;i<dim;i++)
	{
		v[i]=0;
	}

#ifdef TEST
	cout<<"In default constructor."<<endl;
#endif
}

vec::vec(int d) 
{
	dim = d;
	v = new double[dim];
	if (!v) {
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	short int i;
	for(i=0;i<dim;i++)
	{
		v[i]=0;
	}
#ifdef TEST
	cout<<"In dimension constructor."<<endl;
#endif
}

vec::vec(const vec& b) 
{
	dim = b.dim;
	v = new double[dim];
	if (!v) {
		cerr<<"Fatal error: Memory reservation failed."<<endl;
		abort();
	}
	short int i;
	for (i=0; i<dim; i++)
		v[i] = b.v[i];
#ifdef TEST
	cout<<"In copy constructor."<<endl;
#endif
}

vec::~vec() 
{
	delete[] v;
#ifdef TEST
	cout<<"In destructor."<<endl;
#endif
}

void vec::input() {
	short int i;
	for (i=0; i<dim; i++)
		cin>>v[i];
}

void vec::output() const {
	short int i;
	cout <<'(';
	for (i=0; i<dim-1; i++)
		cout<<v[i]<<", ";
	cout<<v[dim-1]<<") ";
}


double vec::abs() const 
{
	double res = 0;
	short int i;
	for (i=0; i<dim; i++)
		res += v[i]*v[i];
	return sqrt(res);
}

vec vec::operator +(vec const &b) const {
	if (dim!=b.dim) {
		cerr<<"Dimension error in + operator!"<<endl; abort();
	}
	short int i;
	vec res(dim);
	for (i=0; i<dim; i++)
		res.v[i] = v[i]+b.v[i];
	return res;
}

vec vec::operator -(vec const &b) const {
	if (dim!=b.dim) {
		cerr<<"Dimension error in + operator!"<<endl; abort();
	}
	short int i;
	vec res(dim);
	for (i=0; i<dim; i++)
        if(v[i]>b.v[i])
        {
            res.v[i] = v[i]-b.v[i];
        }
        else
        {
            res.v[i] = b.v[i]-v[i];
        }
		
	return res;
}

