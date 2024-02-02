#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector <TreeNode*> children;
    
    TreeNode(T x)
    {
        data = x;
    }
};

TreeNode<int>* createTree();
void replaceWDepth(TreeNode<int> *rootNode, int depth = 0);
void printTree(TreeNode<int> *rootNode);

int main()
{
    TreeNode<int> *root = createTree();
    replaceWDepth(root);
    cout<<endl<<endl;
    printTree(root);
}

void printTree(TreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
        return;
        
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->data<<':';
        for(int i=0; i<subRoot->children.size(); i++)
        {
            cout<<subRoot->children[i]->data<<',';
            pendingNodes.push(subRoot->children[i]);
        }
        cout<<endl;
    }
}

void replaceWDepth(TreeNode<int> *rootNode, int depth)
{
    if(rootNode == nullptr)
        return;
    
    rootNode->data = depth;

    for(int i=0; i<rootNode->children.size(); i++)
        replaceWDepth(rootNode->children[i], depth+1);
}

TreeNode<int>* createTree()
{
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    TreeNode <int> *rootNode = new TreeNode(rootData);
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<"no of children of "<<subRoot->data<<':';
        int noOfChildren;
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            cout<<"enter data of the "<<i<<"th child of "<<subRoot->data<<':';
            int childData;
            cin>>childData;

            TreeNode<int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}