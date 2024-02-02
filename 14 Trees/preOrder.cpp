#include <iostream>
#include <vector>
#include <queue>

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

TreeNode <int>* createTree();
void preOrder(TreeNode <int> *rootNode);
void printTree(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<endl;
    printTree(root);
    cout<<endl;
    preOrder(root);
}

void printTree(TreeNode <int> *rootNode)
{
    if(rootNode == nullptr)
        return;
    
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        rootNode = pendingNodes.front();
        pendingNodes.pop();

        cout<<rootNode->data<<":";

        for(int i=0; i<rootNode->children.size(); i++)
        {
            cout<<rootNode->children[i]->data<<',';
            pendingNodes.push(rootNode->children[i]);
        }

        cout<<endl;

        // for(int i=0; i<rootNode->children.size(); i++)
        //     printTree(rootNode->children[i]);
    }
}

void preOrder(TreeNode <int> *rootNode)
{
    if(rootNode == nullptr)
        return;
    
    cout<<rootNode->data<<' ';
    
    for(int i=0; i<rootNode->children.size(); i++)
        preOrder(rootNode->children[i]);
}

TreeNode <int>* createTree()
{
    cout<<"root data: ";
    int rootData;
    cin>>rootData;

    TreeNode <int> *rootNode = new TreeNode(rootData);
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int noOfChildren;
        cout<<"no of children of "<<subRoot->data<<':';
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<':';
            int childData;
            cin>>childData;

            TreeNode <int> *childNode = new TreeNode(childData);
            subRoot->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return rootNode;
}