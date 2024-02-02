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
Node* swapNodes(Node *head, int i, int j);

int main()
{
    int t, i, j;
    cin>>t;

    Node **ans = new Node*[t];

    for(int k=0; k<t; k++)
    {
        ans[k] = createList();
        cin>>i>>j;
        ans[k] = swapNodes(ans[k], i , j);
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* swapNodes(Node *head, int i, int j)
{
    if(i == j)
        return head;

    Node *INode = head;
    Node *JNode = head;
    Node *IPrev = nullptr;
    Node *JPrev = nullptr;

    for(int k=0; k<min(i, j); k++)
    {
        IPrev = INode;
        INode = INode->next;
        JPrev = JNode;
        JNode = JNode->next;
    }

    for(int k=0; k<max(i, j) - min(i, j); k++)
    {
        JPrev = JNode;
        JNode = JNode->next;
    }

    if(IPrev == nullptr)
    {
        IPrev = INode->next;                     // ACTING AS TEMP VARIABLE || INext
        INode->next = JNode->next;
        JPrev->next = INode;
        JNode->next = IPrev;
        return JNode;
    }

    Node *tmp = nullptr;

    JPrev->next = INode;
    IPrev->next = JNode;
    tmp = INode->next;
    INode->next = JNode->next;
    JNode->next = tmp;

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