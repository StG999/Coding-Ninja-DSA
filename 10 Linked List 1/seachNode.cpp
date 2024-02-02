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

int searchNode(Node *head, int value)
{
    int index = 0;

    while(head != nullptr)
    {
        if(head->data == value)
            return index;
        
        head = head->next;
        index++;
    }

    return -1;
}

int main()
{
    int t;
    cin>>t;

    int ans[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        
        int key;
        cin>>key;
        
        ans[i] = searchNode(head, key);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}