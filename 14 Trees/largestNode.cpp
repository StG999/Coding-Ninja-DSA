#include <iostream>
#include <queue>
#include <vector>

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

TreeNode <int>* createTree();
int largestNode(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *head = createTree();
    int largest = largestNode(head);
    cout<<"largest node: "<<largest;
}

int largestNode(TreeNode <int> *rootNode)
{
    int largest = rootNode->data;

    for(int i=0; i<rootNode->children.size(); i++)
        largest = max(largest, largestNode(rootNode->children[i]));
    
    return largest;
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
        TreeNode <int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int noOfChildren;
        cout<<"no of children of "<<subRoot->data<<": ";
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            int childData;
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<": ";
            cin>>childData;

            TreeNode <int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}