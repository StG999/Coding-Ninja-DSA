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

class Pair
{
    public:
        bool balanced;
        int height;
    
    Pair(int height, bool balanced)
    {
        this->balanced = balanced;
        this->height = height;
    }
};

BinaryTreeNode<int>* createTree();
void printTree(BinaryTreeNode<int> *rootNode);
Pair balanced(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl;
    balanced(root).balanced ? cout<<"True." : cout<<"False.";
}

Pair balanced(BinaryTreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
    {
        Pair ans(-1, false);
        return ans;
    }

    Pair lAns(0, true), rAns(0, true);

    if(rootNode->left != nullptr)
    {
        lAns = balanced(rootNode->left);
        if(!lAns.balanced)
            return lAns;
    }

    if(rootNode->right != nullptr)
    {
        rAns = balanced(rootNode->right);
        if(!rAns.balanced)
            return rAns;
    }
    
    int heightDiff = abs(lAns.height-rAns.height);
    if(heightDiff >= -1 && heightDiff <= 1)
    {
        Pair ans(max(lAns.height, rAns.height)+1, true);
        return ans;
    }

    Pair ans(heightDiff, false);
    return ans;
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