#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node <T> *next;
    
    Node(T x)
    {
        data = x;
        next = nullptr;
    }
};

template <typename T>
class QueueUsingLL
{
    Node <T> *head;
    Node <T> *tail;
    int size;

    public:
        QueueUsingLL()
        {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
    
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if(isEmpty())
        {
            head = new Node <T> (element);
            tail = head;
            size++;
            return;
        }

        Node <T> *newNode = new Node <T> (element);
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Error: Stack Empty.\n";
            return 0;
        }

        return head->data;
    }

    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Error: Queue Underflow.\n";
            return 0;
        }
        T ans = head->data;
        Node <T> *tmp = head->next;
        delete head;
        head = tmp;
        size--;
        return ans;
    }
};