#include <iostream>
// 011 41400400

// kalkaji
// srinivas puri

using namespace std;

class Polynomial{
    int *degCoeff;
    int capacity;

    public:
        // Default Constructor
        Polynomial()
        {
            degCoeff = new int[5];
            capacity = 5;

            for(int i=0; i<capacity; i++)
                degCoeff[i] = 0;
        }

        // Copy Constructor
        Polynomial(const Polynomial &p2)
        {
            degCoeff = new int[p2.capacity];
            capacity = p2.capacity;

            for(int i=0; i<capacity; i++)
                degCoeff[i] = p2.degCoeff[i];
        }

        // Functions
        void doubleSize()
        {
            int *newArr = new int[capacity*2];
            for(int i=0; i<capacity*2; i++)
            {
                if(i<capacity)
                    newArr[i] = degCoeff[i];
                
                else
                    newArr[i] = 0;
            }

            capacity *= 2;
            delete [] degCoeff;
            degCoeff = newArr;
        }

        void setCoeff(int i, int value)
        {
            if(i>=capacity)
                while(i>=capacity)
                    doubleSize();
                
            degCoeff[i] = value;
        }

        int getCapacity() const
        {
            return capacity;
        }

        void print() const
        {
            for(int i=0; i<capacity; i++)
            {
                if(degCoeff[i] == 0)
                    continue;
                
                else if(degCoeff[i] > 0)
                    cout<<'+'<<' '<<degCoeff[i]<<'x'<<i<<" ";
                
                else if(degCoeff[i] < 0)
                    cout<<'-'<<' '<<-1*degCoeff[i]<<'x'<<i<<" ";
            }

            cout<<endl;
        }

        // Operator Overloading
        // Copy Assignment Operator
        void operator=(Polynomial const &p2)
        {
            degCoeff = new int[p2.capacity];
            capacity = p2.capacity;

            for(int i=0; i<capacity; i++)
                degCoeff[i] = p2.degCoeff[i];
        }

        // + Operator
        Polynomial operator+(Polynomial const &p2)
        {
            Polynomial p3;
            while(p3.capacity <= max(capacity, p2.capacity))
                p3.doubleSize();

            for(int i=0; i<min(p2.capacity, capacity); i++)
                p3.degCoeff[i] = degCoeff[i] + p2.degCoeff[i];
            
            for(int i=min(p2.capacity, capacity); i<max(p2.capacity, capacity); i++)
            {
                if(capacity<p2.capacity)
                    p3.degCoeff[i] = p2.degCoeff[i];
                
                else
                    p3.degCoeff[i] = degCoeff[i];
            } 

            return p3;
        }

        // - Operator
        Polynomial operator-(Polynomial const &p2)
        {
            Polynomial p3;
            while(p3.capacity < max(capacity, p2.capacity))
                p3.doubleSize();
            
            for(int i=0; i<min(capacity, p2.capacity); i++)
                p3.degCoeff[i] = degCoeff[i] - p2.degCoeff[i];
            
            for(int i=min(capacity, p2.capacity); i<max(capacity, p2.capacity); i++)
            {
                if(capacity>p2.capacity)
                    p3.degCoeff[i] = degCoeff[i];

                else
                    p3.degCoeff[i] = p2.degCoeff[i];
            }

            return p3;
        }

        // * Operator
        Polynomial operator*(Polynomial const &p2)
        {
            Polynomial p3;
            while(p3.capacity < max(capacity, p2.capacity))
                p3.doubleSize();
            p3.doubleSize();

            for(int i=0; i<capacity; i++)
            {
                if(degCoeff[i] != 0)
                    for(int j=0; j<p2.capacity; j++)
                    {
                        if(p2.degCoeff[j] == 0)
                            continue;
                        
                        p3.degCoeff[i+j] += degCoeff[i]*p2.degCoeff[j];
                    }
            }

            return p3;
        }


};