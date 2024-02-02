#include <iostream>
#include "polynomialClass.cpp"

using namespace std;

int main(void)
{
    // Polynomial p1;
    // p1.setCoeff(0, 4);
    // p1.setCoeff(1, 2);
    // p1.setCoeff(2, -3);
    // p1.setCoeff(3, 1);
    // // Polynomial p2(p1);

    // Polynomial p2;
    // p2.setCoeff(1,1);
    // p2.setCoeff(3,2);
    // p2.setCoeff(5,-4);

    // Polynomial p3 = p1 + p2;
    // p1.print();
    // p2.print();
    
    // p3.print();
 
    Polynomial p1, p2, p3;

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int tmp;
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        p1.setCoeff(arr[i], tmp);
    }

    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++)
    {
        cin>>tmp;
        p2.setCoeff(arr[i], tmp);
    }

    cin>>n;
    switch(n)
    {
        // + Operator
        case 1:
        p3 = p1 + p2;
        p3.print();
        break;
        
        // - Operator
        case 2:
        p3 = p1 - p2;
        p3.print();
        
        break;

        // * Operator
        case 3:
        p3 = p1 * p2;        
        p3.print();
        break;

        // Copy Constructor
        case 4:
        {
        Polynomial p4(p1);        
        p4.print();
        break;
        }
        
        // = Operator
        case 5:
        p3 = p2;
        p3.print();
        break;
    }
}