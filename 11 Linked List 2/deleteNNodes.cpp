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
Node* deleteEveryNNodes(Node *head, int m, int n);

int main()
{
    int t, m, n;
    cin>>t;

    Node **ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        cin>>m>>n;
        ans[i] = deleteEveryNNodes(head, m, n);
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* deleteEveryNNodes(Node *head, int m, int n)
{
    /// deletes N nodes after every M nodes.
    if(m == 0 && n != 0)
        return nullptr;

    Node *current = head;
    Node *last = nullptr;
    Node *first = nullptr;

    while(current != nullptr)
    {
        for(int i=0; i<m-1; i++)
        {
            if(current == nullptr)
                return head;

            current = current->next;
        }

        last = current;
        
        for(int i=0; i<n+1; i++)
        {
            if(current == nullptr)
            {
                last->next = nullptr;
                return head;
            }
            current = current->next;
        }

        first = current;

        last->next = first;
    }

    return head;
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