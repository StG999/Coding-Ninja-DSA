#include <iostream>

using namespace std;

class Node
{
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
        if(head == nullptr)
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
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* appendLastNtoFirst(Node *head, int n)
{
    int size = 0;
    Node *current = head;

    while(current->next != nullptr)
    {
        size++;
        current = current->next;
    }
    size++;

    current->next = head;
    current = head;

    for(int i=0; i<size-n-1; i++)
        current = current->next;
    
    Node *tmp = current->next;
    current->next = nullptr;
    head = tmp;

    // current->next = head;
    // head = current->next;
    // current->next = nullptr;
    return head;
}

// Node* appendLastNtoFirst(Node *head, int n)
// {

// }

int main()
{
    int t;
    cin>>t;
    Node *head[t];

    for(int i=0; i<t; i++)
    {
        head[i] = createList();
        int n;
        cin>>n;
        head[i] = appendLastNtoFirst(head[i], n);
    }

    for(int i=0; i<t; i++)
        printList(head[i]);
}