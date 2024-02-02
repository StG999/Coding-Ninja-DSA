#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

    Node(int x)
    {
        data = x;
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
Node* kReverse(Node *head, int k);

int main()
{
    int t, k;
    cin>>t;

    Node** ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        ans[i] = createList();
        cin>>k;
        ans[i] = kReverse(ans[i], k);
    }
    
    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* kReverse(Node *head, int k)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    Node *last = head;

    for(int i=0; i<k-1; i++)
    {
        if(last->next != nullptr)
            last = last->next;
    }
    
    Node *nextHead = last->next;
    last->next = nullptr;

    Pair ans = reverseList_body(head);
    
    head = ans.head;
    last = ans.tail;

    nextHead = kReverse(nextHead, k);

    last->next = nextHead;

    return head;
}

Node* reverseList(Node *head)
{
    return reverseList_body(head).head;
}

Pair reverseList_body(Node *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        Pair ans(head, head);
        return ans;
    
    }

    Pair ans = reverseList_body(head->next);

    ans.tail->next = head;
    ans.tail = head;

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