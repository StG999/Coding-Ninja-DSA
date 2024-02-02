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

int midPoint(Node *head)
{
    if(head == nullptr)
        return -1;

    Node *fast = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {
        head = head->next;
        fast = fast->next->next;
    }

    return head->data;
}

int main(void)
{
    int t;
    cin>>t;
    Node *head[t];
    int ans[t];

    for(int i=0; i<t; i++)
    {
        head[i] = createList();
        ans[i] = midPoint(head[i]);
    }
    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;   
}