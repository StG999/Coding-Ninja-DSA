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

int main(){
    int t;
    cin>>t;

    int *ans = new int[t];

    for(int i=0; i<t; i++)
    {
        Node *head = createList();
        int counter = -1, key;
        cin>>key;
        ans[i] = findNode_body(head, key);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}

int findNode_body(Node *head, int key)
{
    if(head == nullptr)
        return 0;

    if(head->data == key)
        return 1;
    
    int ans = findNode_body(head->next, key) + 1;

    return ans;
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