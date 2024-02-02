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

Node* createList();
void printList(Node *head);
Node* oddEvenSeperate(Node *head);

int main()
{
    int t;
    cin>>t;

    Node **ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        ans[i] = oddEvenSeperate(head);
        cout<<"H\n";
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* oddEvenSeperate(Node *head)
{
    Node *oddHead = nullptr, *evenHead = nullptr, *oddTail = nullptr, *evenTail = nullptr;

    while(head != nullptr)
    {
        if(head->data % 2 == 0)
        {
            if(evenHead == nullptr)
            {
                evenHead = head;
                evenTail = evenHead;
                head = head->next;
            }

            else
            {
                evenTail->next = head;
                evenTail = head;
                head = head->next;
            }
        }

        else
        {
                // cout<<"H\n";
            if(oddHead == nullptr)
            {
                oddHead = head;
                oddTail = oddHead;
                head = head->next;
            }

            else
            {
                oddTail->next = head;
                oddTail = head;
                head = head->next;
            }
        }
    }
    if(oddTail != nullptr)
        oddTail->next = evenHead;
    evenTail->next = nullptr;

    if(oddHead != nullptr)
        return oddHead;

    return evenHead;
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