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

class Pair
{
    public:
        Node *head;
        Node *tail;
    
    Pair(Node *h, Node *t)
    {
        head = h;
        tail = t;
    }
};

Node* createList();
void printList(Node *head);
Pair reverseList_body(Node *head);
Node* reverseList(Node *head);

int main()
{
    Node *head = createList();
    head = reverseList(head);
    printList(head);
}

Node* reverseList(Node *head)
{
    Pair ans = reverseList_body(head);
    return ans.head;
}

Pair reverseList_body(Node *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        Pair ans(head, head);
        return ans;
    }

    Pair smallAns = reverseList_body(head->next);

    smallAns.tail->next = head;
    head->next = nullptr;

    Pair ans(smallAns.head, head);
    return ans;
}

void printList(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<' ';
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