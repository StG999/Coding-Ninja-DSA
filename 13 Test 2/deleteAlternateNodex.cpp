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
void deleteAlternateNode(Node *head);

int main()
{
    Node *head = createList();
    deleteAlternateNode(head);
    printList(head);
}

void deleteAlternateNode(Node *head)
{
    Node *next2next = head->next->next;

    while(head != nullptr && head->next != nullptr)
    {
        delete head->next;
        head->next = next2next;
        head = next2next;
        if(next2next != nullptr && next2next->next != nullptr)
            next2next = next2next->next->next;
    }
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