#include <iostream>

using namespace std;

template <typename T>
class DEQueue
{
    T *data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;

    public:
        DEQueue(int s)
        {
            data = new T[s];
            firstIndex = 0;
            nextIndex = 0;
            capacity = s;
            size = 0;
        }
    
    void insertFront(T element)
    {
        if(size == capacity)
        {
            cout<<-1<<endl;
            return;
        }

        // int size;
        // if(nextIndex > firstIndex)
        //     size = nextIndex - firstIndex;
        
        // else
        //     size = capacity - (firstIndex - nextIndex);

        int counter;
        nextIndex == 0 ? counter = capacity - 1 : counter = nextIndex - 1;
        for(int i=0; i<size; i++)
        {
            if(counter = capacity - 1)
                data[0] = data[counter];
            
            else
                data[counter + 1] = data[counter];
                
            counter--;

            if(counter < 0)
                counter = capacity - 1;
        }

        nextIndex = (nextIndex + 1) % capacity;

        data[firstIndex] = element;
        size++;
    }

    void insertRear(T element)
    {
        if(size == capacity)
        {
            cout<<-1<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }

    void deleteFront()
    {
        firstIndex = (firstIndex + 1) % capacity;
        size--;
    }

    void deleteRear()
    {
        if(nextIndex == 0)
        {
            nextIndex = capacity - 1;
            size--;
            return;
        }

        nextIndex--;
        size--;
    }

    T getFront()
    {
        if(size == 0)
            return -1;

        return data[firstIndex];
    }

    T getRear()
    {
        if(size == 0)
            return -1;
        
        return data[nextIndex - 1];
    }

    void print()
    {
        int counter = firstIndex;
        for(int i=0; i<size; i++)
        {
            cout<<data[counter]<<' ';
            counter = (counter + 1) % capacity;
        }
        cout<<endl;
    }
};

int main()
{
    DEQueue <int> queue(5);
    int x;

    while(true)
    {
        cout<<"-------------------------\n";
        cin>>x;

        switch(x)
        {
            case -1:
            {
                return 0;
            }

            case 0:
            {
                int element;
                cin>>element;
                queue.insertFront(element);
                continue;
            }

            case 1:
            {
                int element;
                cin>>element;
                queue.insertRear(element);
                continue;
            }

            case 2:
            {
                queue.deleteFront();
                continue;
            }

            case 3:
            {
                queue.deleteRear();
                continue;
            }

            case 4:
            {
                int element = queue.getFront();
                cout<<element<<endl;
                continue;
            }

            case 5:
            {
                int element = queue.getRear();
                cout<<element<<endl;
                continue;
            }

            case 6:
            {
                queue.print();
            }
        }
    }
}