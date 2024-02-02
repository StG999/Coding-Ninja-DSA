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

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

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

Node* deleteNode(Node *head, int index)
{
    int i = 0;
    Node *current = head;

    if(index == 0)
    {
        current = head->next;
        delete head;
        return current;
    }

    while(i < index - 1 && current != NULL)
    {
        i++;
        current = current->next;
    }

    if(current == NULL)
        return head;

    Node *next = current->next;
    current->next = next->next;
    delete next;

    return head;
}

int main()
{
    int *t = new int;
    cin>>*t;

    Node *head[*t];
    // int index[*t];

    for(int i=0; i<*t; i++)
    {
        head[i] = createList();
        int index;
        cin>>index;
        
        head[i] = deleteNode(head[i], index);
    }

    for(int i=0; i<*t; i++)
        printList(head[i]);
}