#include <cctype>
#include <iostream>

using namespace std;

template <typename T>
class StackUsingArray
{
    T *arr;
    int nextIndex;
    int capacity;

    public:
        StackUsingArray(int size)
        {
            capacity = size;
            arr = new T[size];
            nextIndex = 0;
        }

        bool isEmpty()
        {
            return nextIndex == 0;
        }

        int getSize()
        {
            return nextIndex;
        }

        int getCapacity()
        {
            return capacity;
        }

        T top()
        {
            if(isEmpty())
            {
                cout<<"Error: Stack Empty\n";
                return 0;
            }

            return arr[nextIndex-1];
        }

        void push(T element)
        {
            if(nextIndex == capacity)
            {
                T *newArr = new T[capacity*2];

                for(int i=0; i<capacity; i++)
                    newArr[i] = arr[i];
                
                delete []arr;
                arr = newArr;
                capacity *= 2;
                arr[nextIndex] = element;
                nextIndex++;

                return;
            }

            arr[nextIndex] = element;
            nextIndex++;

            return;
        }

        T pop()
        {
            if(isEmpty())
            {
                cout<<"Error: Stack Underflow\n";
                return 0;
            }

            nextIndex--;
            return arr[nextIndex];
        }
};