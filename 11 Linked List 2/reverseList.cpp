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
Node* reverseList(Node *head);
Pair reverseListBetter_body(Node *head);
Node* reverseListBetter(Pair ans);

int main()
{
    int t;
    cin>>t;
    Node **ans = new Node*[t];

    int counter = 0;

    for(int i=0; i<t; i++)
    {
        ans[i] = createList();
        ans[i] = reverseListBetter(ans[i]);
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Pair reverseListBetter_body(Node *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        Pair ans(head, head);
        return ans;
    }

    Pair ans = reverseListBetter_body(head->next);

    ans.tail->next = head;
    head->next = nullptr;
    ans.tail = head;

    Pair finalAns(ans.head, head);

    return finalAns;
}

Node* reverseListBetter(Node *head)
{
    return reverseListBetter_body(head).head;
}


Node* reverseList(Node *head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *tmp = reverseList(head->next);

    Node *last = tmp;
    
    while(last->next != nullptr)
        last = last->next;
    
    last->next = head;
    head->next = nullptr;

    return tmp;
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
    int value;
    cin>>value;

    Node *head = nullptr;
    Node *tail = nullptr;

    while(value != -1)
    {
        if(head == nullptr)
        {
            head = new Node(value);
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