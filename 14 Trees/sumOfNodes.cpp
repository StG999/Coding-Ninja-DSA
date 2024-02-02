#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector <TreeNode *> children;
    
    TreeNode(T x)
    {
        data = x;
    }
};

TreeNode <int>* createTreeLevelWise();
int sumOfNodes(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTreeLevelWise();
    cout<<"Sum: "<<sumOfNodes(root);
}

int sumOfNodes(TreeNode <int> *rootNode)
{
    int sum = rootNode->data;

    for(int i=0; i<rootNode->children.size(); i++)
        sum += sumOfNodes(rootNode->children[i]);
    
    return sum;
}

TreeNode <int>* createTreeLevelWise()
{
    queue <TreeNode<int>*> pendingNodes; 
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    TreeNode <int> *rootNode = new TreeNode(rootData);
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<"no of children of "<<subRoot->data<<": ";
        int noOfChildren;
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<": ";
            int childData;
            cin>>childData;

            TreeNode <int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}