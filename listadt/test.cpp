#include<iostream>
using namespace std;
class test1
{
    int a;
public:
    test1()
    {
        a=0;
    }
    void setA(int a)
    {
        this->a = a;
    }
    int getA()
    {
        return a;
    }
};

class test2:public test1
{
    int b;
public:
    test2()
    {
        b=0;
    }
    void setB(int b)
    {
        this->b = b;
    }
    int getB()
    {
        return b;
    }
};

int main()
{
    test2 *objptr;
    test2 obj2;
    objptr=&obj2;
    objptr->setA(5);
    cout<<objptr->getA()<<endl;
    test1 *obj2ptr = (test1*)objptr;
    obj2ptr->setA(10);
    cout<<obj2ptr->getA()<<endl;
    return 0;
}