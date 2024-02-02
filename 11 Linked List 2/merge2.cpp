#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    Node(int value)
    {
        next = nullptr;
        data = value;
    }
};

Node* createList();
void printList(Node *head);
Node* mergeLists(Node *head1, Node *head2);

int main()
{
    int t;
    cin>>t;
    Node **ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        Node *head1 = createList();
        Node *head2 = createList();

        // printList(head1);
        // printList(head2);

        ans[i] = mergeLists(head1, head2);
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
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

Node* mergeLists(Node *head1, Node *head2)
{
    Node *finalHead = nullptr;
    Node *finalTail = nullptr;

    if(head1->data >= head2->data)
    {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
    }

    else
    {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
    }

    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->data < head2->data)
        {
            finalTail->next = head1;
            finalTail = head1;
            head1 = head1->next;
        }

        else
        {
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
    }

    while(head1 != nullptr)
    {
        finalTail->next = head1;
        finalTail = head1;
        head1 = head1->next;
    }

    while(head2 != nullptr)
    {
        finalTail->next = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    
    return finalHead;
}