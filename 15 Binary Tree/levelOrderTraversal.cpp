#include <iostream>
#include <queue>

using namespace std;

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
void levelOrderTraversal(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl;
    levelOrderTraversal(root);
}

void levelOrderTraversal(BinaryTreeNode<int> *rootNode)
{
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);
    pendingNodes.push(nullptr);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        if(subRoot == nullptr && !pendingNodes.empty())
        {
            cout<<endl;
            pendingNodes.push(nullptr);
            continue;
        }

        cout<<subRoot->data<<' ';

        if(subRoot->left != nullptr)
            pendingNodes.push(subRoot->left);

        if(subRoot->right != nullptr)
            pendingNodes.push(subRoot->right);
    }
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