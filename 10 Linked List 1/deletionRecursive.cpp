#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
    Node(int value)
    {
        data = value;
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

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

Node* deleteNode(Node *head, int index)
{
    if(head == NULL)
        return head;
    
    Node *second = deleteNode(head->next, index-1);

    if(index == 0)
    {
        // Node *newHead = head->next;
        delete head;
        head = second;
        return head;
    }

    else
    {
        head->next = second;
        return head;
    }
}

int main()
{
    int t;
    cin>>t;

    Node *heads[t];

    for(int i=0; i<t; i++)
    {
        heads[i] = createList();
        int index;
        cin>>index;

        heads[i] = deleteNode(heads[i], index);
    }

    for(int i=0; i<t; i++)
        printList(heads[i]);
}