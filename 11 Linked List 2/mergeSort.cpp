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

Node* createList();
void printList(Node *head);
Node* merge(Node *head1, Node *head2);
Node* mergeSort(Node *head, Node *end);
Node* midList(Node *head);
Node* mergeSort(Node *head, Node *end);
Node* merge(Node *head1, Node *head2);

int main()
{
    int t;
    cin>>t;

    Node **ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        // cout<<"here\n";
        ans[i] = mergeSort(head, nullptr);
    }
    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* merge(Node *head1, Node *head2)
{
    Node *finalHead = nullptr;
    Node *finalTail = nullptr;

    if(head1->data <= head2->data)
    {
        finalHead = head1;
        finalTail = head1;
        head1 = head1->next;
    }
    
    else
    {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
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

Node* mergeSort(Node *head, Node *end)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    Node *middle = midList(head);

    Node *head2 = mergeSort(middle->next, nullptr);
    middle->next = nullptr;
    Node *head1 = mergeSort(head, nullptr);

    return merge(head1, head2);
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

Node* midList(Node *head)
{
    Node *fast = head->next;
    while(fast != nullptr && fast->next != nullptr )
    {
        head = head->next;
        fast = fast->next->next;
    }

    return head;
}