#include <iostream>
using namespace std;

template <typename T>
class queueUsingArray
{
    T *data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;

    public:
        queueUsingArray(int x)
        {
            capacity = x;
            data = new T[x];
            size = 0;
            firstIndex = 0;
            nextIndex = 0;
        }
    
    int getCapacity()
    {
        return capacity;
    }
    
    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Error: Queue Empty.\n";
            return 0;
        }
        return data[firstIndex];
    }

    void enqueue(T element)
    {
        if(size == capacity)
        {
            // cout<<"Error: Queue Overflow.\n";
            // return;
            
            T *newArr = new T[capacity*2];
            for(int i=0; i<capacity; i++)
            {
                newArr[i] = data[firstIndex];
                firstIndex = (firstIndex + 1) % capacity;
            }
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            delete [] data;
            data = newArr;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }

    T dequeue()
    {
        if(size == 0)
        {
            // cout<<"Error: Queue Empty.\n";
            // return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
};