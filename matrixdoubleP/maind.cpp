#include "vector.cpp"
#include "matrixd.cpp"

int main()
{

    short int row;
    short int col;

    //constructing matrix m1;
    cout<<"Enter the number of rows and columns for matrix m1"<<endl;
    cin>>row>>col;
    matrix m1(row,col);
    cout<<"Enter Values of "<<row<<" X "<<col<<" matrix m1"<<endl;
    m1.input();
    cout<<"Showing values for matrix m1"<<endl;
    m1.output(); 

    //constructing matrix m2
    cout<<"Enter the number of rows and columns for matrix m2"<<endl;;
    cin>>row>>col;
    matrix m2(row,col);
    cout<<"Enter Values of "<<row<<" X "<<col<<" matrix m2"<<endl;
    m2.input();
    cout<<"Showing values for matrix m2"<<endl;
    m2.output(); 

    //Addition of matrix
    matrix m3 = m1+m2;
    cout<<"Showing values for matrix m3 = m1 + m2"<<endl;
    m3.output(); 

    //Absolute difference of matrix
    matrix m4 = m1-m2;
    cout<<"Showing values for matrix m4 = m1 ~ m2"<<endl;
    m4.output();

     
    cout<<"\nEnd of Program"<<endl;




    return 1;

}


