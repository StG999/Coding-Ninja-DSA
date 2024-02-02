#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    Node(int x)
    {
        data = x;
        next == nullptr;
    }
};

template <typename T>
class BinaryTreeNode
{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    
    BinaryTreeNode(T x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTreeNode<int>* createTree();
void printTree(BinaryTreeNode<int> *rootNode);
vector<Node*> levelWiseLinkedList(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl;
    // printTree(root);
    vector<Node*> ans= levelWiseLinkedList(root);
    cout<<"HERE\n";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<' ';

    cout<<endl;
}

vector<Node*> levelWiseLinkedList(BinaryTreeNode<int> *rootNode)
{
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);
    pendingNodes.push(nullptr);
    vector<Node*> heads;
    Node *head = nullptr, *tail = nullptr;
    int i=0;

    while(!pendingNodes.empty())
    {
        cout<<i++;
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        if(subRoot == nullptr && !pendingNodes.empty())
        {
            heads.push_back(head);
            head = nullptr;
            tail = head;
            pendingNodes.push(nullptr);
            continue;
        }
        
        if(head == nullptr)
        {
            head = new Node(subRoot->data);
            tail = head;
        }

        else
        {
            Node *newNode = new Node(subRoot->data);
            tail->next = newNode;
            tail = newNode;
        }

        if(subRoot->left != nullptr)
            pendingNodes.push(subRoot->left);

        if(subRoot->right != nullptr)
            pendingNodes.push(subRoot->right);
    }

    return heads;
}

void printTree(BinaryTreeNode<int> *rootNode)
{
    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->data<<':';
        if(subRoot->left != nullptr)
        {
            cout<<"L:"<<subRoot->left->data<<',';
            pendingNodes.push(subRoot->left);
        }

        if(subRoot->right != nullptr)
        {
            cout<<"R:"<<subRoot->right->data;
            pendingNodes.push(subRoot->right);
        }

        cout<<endl;
    }
}

BinaryTreeNode<int>* createTree()
{
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    BinaryTreeNode<int> *rootNode = new BinaryTreeNode(rootData);
    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int childData;
        cout<<"enter data of left child of "<<subRoot->data<<':';
        cin>>childData;

        if(childData != -1)
        {
            BinaryTreeNode<int> *childNode = new BinaryTreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->left = childNode;
        }

        cout<<"enter data of right child of "<<subRoot->data<<':';
        cin>>childData;

        if(childData != -1)
        {
            BinaryTreeNode<int> *childNode = new BinaryTreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->right = childNode;
        }
    }

    return rootNode;
}