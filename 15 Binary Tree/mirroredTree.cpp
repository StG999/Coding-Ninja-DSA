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
void mirrorTree(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl;
    mirrorTree(root);
    printTree(root);
}

void mirrorTree(BinaryTreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
        return;
    
    BinaryTreeNode<int> *tmpNode = rootNode->left;
    rootNode->left = rootNode->right;
    rootNode->right = tmpNode;

    mirrorTree(rootNode->left);
    mirrorTree(rootNode->right);
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