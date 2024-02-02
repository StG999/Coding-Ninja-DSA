#include <iostream>

using namespace std;

class ComplexNo{
    public:
        int real;
        int imaginary;
    
    ComplexNo(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void add(ComplexNo c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    void multiply(ComplexNo c2)
    {
        ComplexNo tmp(*this);
        real = real*c2.real - imaginary*c2.imaginary;
        imaginary = tmp.real*c2.imaginary + c2.real*tmp.imaginary;
    }

    void print()
    {
        if(imaginary > 0)
            cout<<real<<" + "<<imaginary<<'i'<<endl;
        
        else if(imaginary == 0)
            cout<<real<<endl;

        else
            cout<<real<<" - "<<-1*imaginary<<'i'<<endl;
    }
};