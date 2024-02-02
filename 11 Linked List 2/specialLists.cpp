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

class DNode
{
    public:
        int data;
        DNode *prev;
        DNode *next;
    
    DNode(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

Node* createList();
DNode* createDList();
void printList(Node *head);
void printDList(DNode *head);
Node* insertList(Node *head, int x, int index);
DNode* insertDList(DNode *head, int x, int index);
Node *createCircularList();
DNode* createCircularDList();
void printCircularList(Node *head);
void printCircularDList(DNode *head);

int main()
{
    Node *head = createList();
    DNode *Dhead = createDList();
    Node *Chead = createCircularList();
    DNode *CDhead = createCircularDList();

    printList(head);
    printDList(Dhead);

    // int x, i;
    // cin>>x>>i;
    // head = insertList(head, x, i);
    // printList(head);
    
    // cin>>x>>i;
    // Dhead = insertDList(Dhead, x, i);

    // printDList(Dhead);

    printCircularList(Chead);
    printCircularDList(CDhead);
}

void printCircularDList(DNode *head)
{
    cout<<head->data<<' ';
    DNode *current = head->next;
    while(current != head)
    {
        cout<<current->data<<' ';
        current = current->next;
    }

    cout<<endl;
}

void printCircularList(Node *head)
{
    cout<<head->data<<' ';
    Node *current = head->next;
    while(current != head)
    {
        cout<<current->data<<' ';
        current = current->next;
    }

    cout<<endl;
}

DNode* createCircularDList()
{
    int x;
    cin>>x;

    DNode *head = nullptr;
    DNode *tail = nullptr;

    while(x != -1)
    {
        if(head == nullptr)
        {
            head = new DNode(x);
            tail = head;
        }

        else
        {
            DNode *newNode = new DNode(x);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cin>>x;
    }

    head->prev = tail;
    tail->next = head;

    return head;
}

Node *createCircularList()
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

    tail->next = head;
    return head;    
}

DNode* insertDList(DNode *head, int x, int index)
{
    if(index == 0)
    {
        DNode *newNode = new DNode(x);
        newNode->next = head;

        return newNode;
    }

    if(index == -1)
    {
        DNode *newNode = new DNode(x);
        head->prev->next = newNode;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;

        return head;
    }

    DNode *current = head;

    while(--index)
        current = current->next;
    
    DNode *newNode = new DNode(x);
    newNode->next = current->next;
    newNode->prev = current;
    if(current->next != nullptr)
        current->next->prev = newNode;
    current->next = newNode;

    return head;
}

Node* insertList(Node *head, int x, int index)
{
    if(index == 0)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        return newNode;
    }

    Node *current = head;

    while(--index)
        current = current->next;
    
    Node *newNode = new Node(x);
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printDList(DNode *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
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

DNode* createDList()
{
    int x;
    cin>>x;

    DNode *head = nullptr;
    DNode *tail = nullptr;

    while(x != -1)
    {
        if(head == nullptr)
        {
            head = new DNode(x);
            tail = head;
        }

        else
        {
            DNode *newNode = new DNode(x);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cin>>x;
    }

    return head;
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