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

TreeNode<int>* createTree();
int secondLargest(TreeNode<int> *rootNode);

int main()
{
    TreeNode<int> *root = createTree();
    cout<<endl<<endl;

    cout<<"secLargest: "<<secondLargest(root);
}

int secondLargest(TreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
        return INT32_MAX;
    
    int largest = rootNode->data, secLargest = largest;

    for(int i=0; i<rootNode->children.size(); i++)
    {
        int smallAns = secondLargest(rootNode->children[i]);
        if(smallAns >= largest)
        {
            secLargest = largest;
            largest = smallAns;
        }

        else if(smallAns > secLargest && smallAns < largest)
        {
            secLargest = smallAns;
        }
    }

    return secLargest;
}

TreeNode<int>* createTree()
{
    int rootData;
    cout<<"root data: ";
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
            int childData;
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<':';
            cin>>childData;

            TreeNode<int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}