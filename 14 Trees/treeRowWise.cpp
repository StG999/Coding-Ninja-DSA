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
        data = x;;
    }
};

TreeNode<int>* createTree();
void printTree(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    printTree(root);
}

void printTree(TreeNode <int> *rootNode)
{
    if(rootNode == nullptr)
        return;
    
    cout<<rootNode->data<<':';

    for(int i=0; i<rootNode->children.size(); i++)
        cout<<rootNode->children[i]->data<<',';
    
    cout<<endl;

    for(int i=0; i<rootNode->children.size(); i++)
        printTree(rootNode->children[i]);
}

TreeNode<int>* createTree()
{
    cout<<"data: ";
    int rootData;
    cin>>rootData;
    TreeNode <int> *rootNode = new TreeNode(rootData);

    int noOfChildren;
    cout<<"no of children of "<<rootData<<": ";
    cin>>noOfChildren;

    for(int i=0; i<noOfChildren; i++)
    {
        TreeNode <int> *child = createTree();
        rootNode->children.push_back(child);
    }

    return rootNode;
}