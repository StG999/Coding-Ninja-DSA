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

Node* duplicateLL(Node *head)
{
    if(head == nullptr)
        return nullptr;

    Node *newHead = new Node(head->data);

    head = head->next;

    while(head != NULL)
    {
        Node *newNode = new Node(head->data);
        if(newHead->next == nullptr)
            newHead->next = newNode;
        newNode->next = head->next;
        head = head->next;
    }

    return newHead;
}

Node *reverseLL(Node *head)
{
    if(head == nullptr)
        return nullptr;

    Node *current = head->next;
    Node *next = current->next;
    Node *prev = head;
    head->next = nullptr;

    while(next != nullptr)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }

    current->next = prev;

    return current;
}

bool palindrome(Node *head)
{
    Node *reversedHead = duplicateLL(head);
    reversedHead = reverseLL(reversedHead);
    Node *tmp = head;

    while(tmp != nullptr && tmp->next != nullptr)
    {
        if(reversedHead->data != head->data)
            return false;
        
        reversedHead = reversedHead->next;
        head = head->next;
        tmp = tmp->next->next;
    }

    return true;
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

int main()
{
    int t;
    cin>>t;
    Node *head[t];

    for(int i=0; i<t; i++)
        head[i] = createList();
    
    for(int i=0; i<t; i++)
        palindrome(head[i]) ? cout<<"True\n" : cout<<"False\n";
}