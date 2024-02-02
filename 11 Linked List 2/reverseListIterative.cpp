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
        next = nullptr;
    }
};

Node* createList();
void printList(Node *head);
Node *reverseList(Node *head);

int main()
{
    Node *head = createList();
    head = reverseList(head);
    printList(head);
}

Node *reverseList(Node *head)
{
    if(head == nullptr)
        return nullptr;
    
    Node *current = head;
    Node *next = head->next;
    Node *prev = nullptr;

    while(current != nullptr)
    {
        current->next = prev;
        prev = current;
        current = next;
        if(next != nullptr)
            next = next->next;
    }

    return prev;
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

Node* createList()
{
    int x;
    cin>>x;

    Node *head = nullptr;
    Node *tail = nullptr;

    while(x != -1)
    {
        if(head == nullptr)
        {
            head = new Node(x);
            tail = head;
        }

        else
        {
            Node *newNode = new Node(x);
            tail->next = newNode;
            tail = newNode;
        }

        cin>>x;
    }

    return head;
}