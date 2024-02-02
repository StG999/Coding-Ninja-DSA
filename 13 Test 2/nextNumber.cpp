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
Node* incrementList(Node *head);

int main()
{
    Node *head = createList();
    head = incrementList(head);
    printList(head);
}

Node* incrementList(Node *head)
{
    head = reverseList(head);
    Node *current = head;
    int carry = 0;
    
    do
    {
        carry = 0;
        (current->data)++;
        if(current->data == 10)
        {
            current->data = 0;

            if(current->next == nullptr)
            {
                current->next = new Node(1);
                carry = 0;
            }

            else
            {
                carry = 1;
                current = current->next;
            }
        }
    }
    while(carry != 0);

    head = reverseList(head);

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
    head->next = nullptr;
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