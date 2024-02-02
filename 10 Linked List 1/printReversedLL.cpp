#include <iostream>
#include <vector>

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

void printReversed(Node *head)
{
    vector <int> stack;
    int n = 0;

    while(head != nullptr)
    {
        stack.push_back(head->data);
        n++;
        head = head->next;
    }

    for(int i=n-1; i>=0; i--)
        cout<<stack[i]<<" ";
    
    cout<<endl;
}

void printReversedRecursive(Node *head)                                             // BEST WAY (maybe)
{
    if(head == nullptr)
        return;
    
    printReversedRecursive(head->next);

    cout<<head->data<<" ";
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
    // Node **head = new Node*[t];
    Node *head[t];

    for(int i=0; i<t; i++)
        head[i] = createList();
    
    for(int i=0; i<t; i++){
        printReversedRecursive(head[i]);
        cout<<endl;}
}