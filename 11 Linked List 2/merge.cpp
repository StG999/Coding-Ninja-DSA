#include <iostream>                                     // THIS IS DEBUGGED. BOTH ARE WORKING

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

void printList(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* merge(Node* head1, Node *head2)
{
    Node *finalHead;
    Node *finalTail;

    if(head1->data <= head2->data)
    {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
        // head1->next = head1;                                                // THIS IS WRITTEN REVERSE. SHOULD'VE BEEN HEAD1 = HEAD1.NEXT 
    }
    
    else
    {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
        // head2->next = head2;
    }

    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->data <= head2->data)
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

int main(void)
{
    int t;
    cin>>t;
    Node *finalHeads[t];

    for(int i=0; i<t; i++)
    {
        Node *head1;
        Node *head2;

        head1 = createList();
        head2 = createList();

        finalHeads[i] = merge(head1, head2);
    }

    for(int i=0; i<t; i++)
        printList(finalHeads[i]);
}