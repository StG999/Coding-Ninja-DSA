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
int leafNodesCount(TreeNode <int> *rootNode);
void printTree(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<endl;
    printTree(root);
    cout<<"No of leaf nodes: "<<leafNodesCount(root);
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

int leafNodesCount(TreeNode <int> *rootNode)
{
    if(rootNode->children.size() == 0)
        return 1;
    
    int ans = 0;

    for(int i=0; i<rootNode->children.size(); i++)
        ans += leafNodesCount(rootNode->children[i]);
    
    return ans;
}

TreeNode <int>* createTree()
{
    int rootData;
    cout<<"root data: ";
    cin>>rootData;

    TreeNode <int> *rootNode = new TreeNode(rootData);
    queue <TreeNode <int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        int noOfChildren;
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<"no of children of "<<subRoot->data<<": ";
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            int childData;
            cout<<"data of "<<i<<"th node of "<<subRoot->data<<": ";
            cin>>childData;
            TreeNode <int> *childNode = new TreeNode<int> (childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}