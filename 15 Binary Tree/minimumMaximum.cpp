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
        int max;
        int min;
    
    Pair(int maximum, int minimum)
    {
        max = maximum;
        min = minimum;
    }
};

BinaryTreeNode<int>* createTree();
void printTree(BinaryTreeNode<int> *rootNode);
Pair minimumMaximum(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl;
    Pair ans = minimumMaximum(root);
    cout<<ans.min<<' '<<ans.max;
}

Pair minimumMaximum(BinaryTreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
    {
        Pair ans(INT_MIN, INT32_MAX);
        return ans;
    }

    int mini = rootNode->data, maxi = rootNode->data;

    if(rootNode->left != nullptr)
    {
        mini = min(mini, minimumMaximum(rootNode->left).min);
        maxi = max(maxi, minimumMaximum(rootNode->left).max);
    }
    
    if(rootNode->right != nullptr)
    {
        mini = min(mini, minimumMaximum(rootNode->right).min);
        maxi = max(maxi, minimumMaximum(rootNode->right).max);
    }

    Pair ans(maxi, mini);
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