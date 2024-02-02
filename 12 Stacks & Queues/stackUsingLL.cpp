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
class StackUsingLL
{
    Node <T> *head;
    int size;

    public:
        StackUsingLL()
        {
            head = nullptr;
            size = 0;
        }

        bool isEmpty()
        {
            return size == 0;
        }

        int getSize()
        {
            return size;
        }

        T top()
        {
            if(head == nullptr)
            {
                cout<<"Error: Stack Empty\n";
                return 0;
            }
            return head->data;
        }

        void push(T element)
        {
            Node <T> *newNode = new Node <T>(element);
            newNode->next = head;
            head = newNode;
            size++;
        }

        T pop()
        {
            if(isEmpty())
            {
                cout<<"Error: Stack Underflow\n";
                return 0;
            }
            T ans = head->data;
            Node <T> *tmpHead = head;
            head = head->next;
            delete tmpHead;
            size--;
            
            return ans;
        }
};