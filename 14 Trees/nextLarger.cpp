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

class Pair
{
    public:
        int nodeData;
        int difference;
    
    Pair(int n, int d)
    {
        nodeData = n;
        difference = d;
    }
};

TreeNode<int>* createTree();
int nextLarger(TreeNode<int> *rootNode, int x);

int main()
{
    int n;
    cout<<"n: ";
    cin>>n;
    TreeNode<int> *root = createTree();
    cout<<endl<<endl;

    cout<<endl<<"next larger: "<<nextLarger(root, n);
}

int nextLarger(TreeNode<int> *rootNode, int x)
{
    if(rootNode == nullptr)
        return INT_MIN;
    
    int ans = rootNode->data;
    int diff = ans - x;

    if(diff < 0)
        diff = -1*diff;

    for(int i=0; i<rootNode->children.size(); i++)
    {
        int smallAns = nextLarger(rootNode->children[i], x);
        if(smallAns > x && (smallAns - x) < diff)
        {
            ans = smallAns;
            diff = smallAns - x;
        }
    }

    return ans;
}

TreeNode<int>* createTree()
{
    int rootData;
    cout<<"root data: ";
    cin>>rootData;

    TreeNode<int> *rootNode = new TreeNode(rootData);
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode<int> *subRoot = pendingNodes.front();
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