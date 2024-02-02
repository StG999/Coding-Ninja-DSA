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

TreeNode <int>* createTree();
bool structurallyIdentical(TreeNode <int> *rootNode1, TreeNode <int> *rootNode2);

int main()
{
    TreeNode<int> *root1 = createTree();
    cout<<endl<<endl;
    TreeNode<int> *root2 = createTree();
    cout<<endl<<endl;
    structurallyIdentical(root1, root2) ? cout<<"True." : cout<<"False.";
}

bool structurallyIdentical(TreeNode <int> *rootNode1, TreeNode <int> *rootNode2)
{
    if(rootNode1 == nullptr || rootNode2 == nullptr)
        return false;
    
    if(rootNode1->data != rootNode2->data || rootNode1->children.size() != rootNode2->children.size())
        return false;
    
    bool ans = true;
    for(int i=0; i<rootNode1->children.size(); i++)
        if(!structurallyIdentical(rootNode1->children[i], rootNode2->children[i]))
            ans = false;
            
    return ans;
}

TreeNode <int>* createTree()
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
        cout<<"no of children of"<<subRoot->data<<':';
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            cout<<"data of the "<<i<<"th child of "<<subRoot->data<<':';
            int childData;
            cin>>childData;

            TreeNode <int> *childNode = new TreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->children.push_back(childNode);
        }
    }

    return rootNode;
}