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
Node* bubbleSort(Node *head);
Node* swapNodes(Node *iNode, Node *iPrev, Node *jNode);

int main()
{
    int t;
    cin>>t;

    Node **ans = new Node*[t];

    for(int i=0; i<t; i++)
    {
        ans[i] = createList();
        ans[i] = bubbleSort(ans[i]);
    }

    for(int i=0; i<t; i++)
        printList(ans[i]);
}

Node* swapNodes(Node *iPrev, Node *iNode, Node *jNode)
{
    iPrev->next = jNode;
    iNode->next = jNode->next;
    jNode->next = iNode;

    return jNode;
}

Node* bubbleSort(Node *head)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    Node *i = head;
    Node *j = head;
    int counter;

    while(j->next != nullptr)
    {
        counter = 0;
        if(i->data > i->next->data)
        {
            if(i == j)
                j = i->next;
            
            else if(i->next == j)
                j = i;

            Node *tmp = i->next;
            i->next = i->next->next;
            tmp->next = i;
            head = tmp;
        }

        i = head;

        while(i->next->next != nullptr)
        {
            if(i->next->data > i->next->next->data)
            {
                if(j == i->next)
                    j = i->next->next;

                else if(j == i->next->next)
                    j = i->next;

                i->next = swapNodes(i, i->next, i->next->next);
                counter++;
            }

            i = i->next;
        }
        
        i = head;
        j = j->next;

        if(counter == 0)
            return head;
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