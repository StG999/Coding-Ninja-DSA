#include <iostream>
#include "complex.cpp"

int main(void)
{
    ComplexNo c1(1, 3);
    ComplexNo *c2 = new ComplexNo(1, -2);
    ComplexNo c3(c1);

    c1.print();
    c2->print();
    c3.print();

    c1.add(*c2);
    c1.print();

    c3.multiply(*c2);
    c3.print();
}