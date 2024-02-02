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
            tail = newNode;
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
}

Node* insertNode(Node *head, int value, int index)
{
    if(head == NULL)
        return head;
    
    Node *second = insertNode(head->next, value, index-1);

    if(index == 0)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head->next = second;
        head = newNode;
    }

    else
    {
        head->next = second;
    }

    return head;
}

int main()
{
    Node *head = createList();
    int value, index;
    cin>>index>>value;

    head = insertNode(head, value, index);

    printList(head);
}