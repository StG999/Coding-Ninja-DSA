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
int greaterThanX(TreeNode<int> *rootNode, int x);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<"\nx: ";
    int x;
    cin>>x;

    cout<<"ans: "<<greaterThanX(root, x);
}

int greaterThanX(TreeNode<int> *rootNode, int x)
{
    if(rootNode == nullptr)
        return -1;

    int ans = 0;

    if(rootNode->data > x)
        ans = 1;
    
    for(int i=0; i<rootNode->children.size(); i++)
        ans += greaterThanX(rootNode->children[i], x);

    return ans;
}

TreeNode <int>* createTree()
{
    int rootData;
    cout<<"root data: ";
    cin>>rootData;

    TreeNode<int> *rootNode = new TreeNode(rootData);
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