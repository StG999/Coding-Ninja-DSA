#include <iostream>
#include "queueUsingLL.h"

using namespace std;

template <typename T>
void queryHandler(QueueUsingLL <T> *queue, int queryNo);

int main()
{
    int q, qNo;
    cin>>q;

    QueueUsingLL <int> queue;

    for(int i=0; i<q; i++)
    {
        cin>>qNo;
        queryHandler(&queue, qNo);
    }
}

template <typename T>
void queryHandler(QueueUsingLL <T> *queue, int queryNo)
{
    switch(queryNo)
    {
        case 1:
        {
            T element;
            cin>>element;

            (*queue).enqueue(element);
            cout<<"Enqueue Successful.\n";
            return;
        }

        case 2:
        {
            cout<<"Dequeued element: "<<(*queue).dequeue()<<endl;
            return;
        }

        case 3:
        {
            cout<<"Element at front of queue: "<<(*queue).front()<<endl;
            return;
        }

        case 4:
        {
            cout<<"Current size of queue: "<<(*queue).getSize()<<endl;
            return;
        }

        case 5:
        {
            (*queue).isEmpty() ? cout<<"True.\n" : cout<<"False.\n";
            return;
        }
    }
}

