#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector <TreeNode<T>*> children;
    
    TreeNode(T x)
    {
        data = x;
    }
};

class Pair
{
    public:
        int index;
        int maxValue;
    
    Pair(int i, int m)
    {
        index = i;
        maxValue = m;
    }
};

TreeNode <int>* createTree();
Pair maxChildSum_body(TreeNode<int> *rootNode);
int maxChildSum(TreeNode <int> *rootNode);

int main()
{
    TreeNode <int> *root = createTree();
    cout<<"\n\nmax child sum: "<<maxChildSum(root);
}

int maxChildSum(TreeNode <int> *rootNode)
{
    return maxChildSum_body(rootNode).index;
}

Pair maxChildSum_body(TreeNode<int> *rootNode)
{
    if(rootNode == nullptr)
    {
        Pair ans(-1, INT_MIN);
        return ans;
    }

    int maxSum = rootNode->data;
    int ans = maxSum;

    for(int i=0; i<rootNode->children.size(); i++)
        maxSum += rootNode->children[i]->data;
    
    for(int i=0; i<rootNode->children.size(); i++)
    {
        int tmpmax = maxChildSum_body(rootNode->children[i]).maxValue;
        if(tmpmax > maxSum)
        {
            maxSum = tmpmax;
            ans = rootNode->children[i]->data;
        }
    }
    
    Pair ansPair(ans, maxSum);
    return ansPair;
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
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<":";
            int childData;
            cin>>childData;

            TreeNode<int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}