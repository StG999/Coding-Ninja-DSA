#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* createList()
{
    int value;
    cin>>value;

    Node *head = NULL;
    Node *tail = NULL;

    while(value != -1)
    {
        if(head == NULL)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = head;
        }

        else
        {
            Node *newNode = new Node(value);
            tail->next = newNode;
            tail = newNode;
        }

        cin>>value;
    }

    return head;
}

void getElement(Node *head, int index)
{
    int i = 0;

    while(true)
    {
        if(head == NULL)
        {    
            cout<<endl;
            return;
        }

        else if(i == index)
        {
            cout<<head->data<<endl;
            return;
        }

        i++;
        head = head->next;
    }
}

int main()
{
    int *t = new int;
    cin>>*t;

    int *index = new int[*t];
    Node *head[*t];
    
    for(int i=0; i<*t; i++)
    {
        head[i] = createList();
        cin>>index[i];
    }

    for(int i=0; i<*t; i++)
        getElement(head[i], index[i]);
}