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
void postOrder(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<endl;
    postOrder(root);
}

void postOrder(TreeNode <int> *rootNode)
{
    for(int i=0; i<rootNode->children.size(); i++)
        postOrder(rootNode->children[i]);
    
    cout<<rootNode->data<<' ';
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
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}