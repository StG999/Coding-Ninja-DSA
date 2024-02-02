#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node* addNode()
{
    int value;
    cin >> value;

    Node *head = NULL;
    Node *tail = NULL;

    while(value != -1)
    {
        if(head == NULL)
        {
            head = new Node(value);
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

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int listSize(Node *head)
{
    int counter = 0;
    while(head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

int main()
{
    int t;
    cin>>t;

    Node *head[t];

    for(int i=0; i<t; i++)
        head[i] = addNode();

    for(int i=0; i<t; i++)
        cout<<listSize(head[i])<<endl;
}