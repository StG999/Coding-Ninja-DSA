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
        next = nullptr;
    }
};

Node* createList()
{
    int value;
    cin>>value;

    Node *head = nullptr;
    Node *tail = nullptr;

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

Node* removeDuplicates(Node *head)
{
    Node *prev = head;
    Node *current = head->next;
    
    while(current != nullptr)
    {
        if(prev->data == current->data)
        {
            Node *tmp = current->next;
            delete current;
            current = tmp;
            prev->next = current;
        }

        else
        {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main()
{
    int t;
    cin>>t;

    Node *head[t];
    
    for(int i=0; i<t; i++)
    {
        head[i] = createList();
        head[i] = removeDuplicates(head[i]);
    }

    for(int i=0; i<t; i++)
        printList(head[i]);
}