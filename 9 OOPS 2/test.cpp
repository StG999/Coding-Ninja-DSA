#include <iostream>

using namespace std;

class Student {
    public :

    int rollNumber;
    static int totalStudents;

    Student() {
        totalStudents++;
    }
};

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

Node* midList(Node *head)
{
    Node *fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        head = head->next;
        fast = fast->next->next;
        cout<<"here\n";
    }

    return head;
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

void printList(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int Student::totalStudents = 20;

int main() {
    // Student s1, s2, s3, s4;
    // cout << Student :: totalStudents;

    // if(nullptr == NULL)
    //      cout<<"true1\n";

    // Node *head = createList();
    // Node *current = head;

    // while(current->next != nullptr)
    //     current = current->next;
    
    // while(head->next != nullptr)
    //     head = head->next;
    
    // cout<<current->data<<endl;
    // cout<<head->data<<endl;

//     Node *list = createList();
//     printList(list);
//     Node *mid= midList(list);
//     cout<<mid->data;
    int i = 5;
    while(i--)
        cout<<i<<" ";
}