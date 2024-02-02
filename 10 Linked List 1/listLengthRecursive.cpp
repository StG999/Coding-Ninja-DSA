#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* createList()
    {
        int value;
        cin>>value;

        Node *head = NULL;
        Node *tail = NULL;

        while(value != -1)
        {
            if(head == NULL)
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

int listLength(Node *head)
{
    if(head == NULL)
        return 0;
    
    int ans = listLength(head->next);

    return ans + 1;
}

int main()
{
    Node *head = createList();

    int ans = listLength(head);
    cout<<ans<<endl;
}