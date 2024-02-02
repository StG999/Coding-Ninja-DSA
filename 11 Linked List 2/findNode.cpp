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
int findNode_body(Node *head, int key);
int findNode(Node *head, int key);

int main()
{
    int t;
    cin>>t;

    int *ans = new int[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        int counter = -1, key;
        cin>>key;
        ans[i] = findNode(head, key);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}

int findNode(Node *head, int key)
{
    if(head == nullptr)
        return -1;
    
    int ans = findNode(head->next, key);

    if(head->data == key)
        return 0;
    
    else if(ans == -1)
        return -1;
    
    else
        return ans + 1;
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