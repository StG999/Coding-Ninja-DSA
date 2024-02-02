#include <iostream>
#include "queueUsingArray.h"

using namespace std;

int main()
{
    queueUsingArray <int> queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<queue.getSize()<<endl;
    cout<<queue.front()<<endl;
    queue.enqueue(40);
    cout<<queue.dequeue()<<endl;
    queue.enqueue(50);
    cout<<queue.getSize()<<endl;
    queue.enqueue(60);
    cout<<queue.getCapacity()<<endl;
    cout<<queue.dequeue()<<endl;
    queue.enqueue(70);
    cout<<queue.getSize()<<endl;
    queue.enqueue(80);
    cout<<queue.getSize()<<endl;
    queue.enqueue(90);
    cout<<queue.getCapacity()<<endl;
}