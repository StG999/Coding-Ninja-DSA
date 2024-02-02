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
        int diameter;
        int height;
    
    Pair(int height = 0, int diameter = 0)
    {
        this->diameter = diameter;
        this->height = height;
    }
};

BinaryTreeNode<int>* createTree();
void printTree(BinaryTreeNode<int> *rootNode);
Pair diameter_body(BinaryTreeNode<int> *rootNode);
int diameter(BinaryTreeNode<int> *rootNode);

int main()
{
    BinaryTreeNode<int> *root = createTree();
    cout<<endl<<endl<<diameter(root);
    // printTree(root);
}

int diameter(BinaryTreeNode<int> *rootNode)
{
    return diameter_body(rootNode).diameter;
}

Pair diameter_body(BinaryTreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
    {
        Pair ans(0, 0);
        return ans;
    }

    Pair leftAns, rightAns, ans;

    if(rootNode->left != nullptr)
        leftAns = diameter_body(rootNode->left);
    
    if(rootNode->right != nullptr)
        rightAns = diameter_body(rootNode->right);
    
    ans.diameter = leftAns.height + rightAns.height;
    ans.height = max(leftAns.height, rightAns.height) + 1;

    if(ans.diameter >= leftAns.diameter && ans.diameter >= rightAns.diameter)
        return ans;
    
    else if(leftAns.diameter >= ans.diameter && leftAns.diameter >= rightAns.diameter)
        return leftAns;
    
    else
        return rightAns;
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