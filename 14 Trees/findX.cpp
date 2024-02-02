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

template <typename T>
TreeNode <T>* createTree(T dataType_definer);
template <typename T>
bool findX(TreeNode<T> *rootNode, T x);
template <typename T>
void printTreeLevelWise(TreeNode <T> *rootNode);

int main()
{
    TreeNode <char> *root = createTree('a');
    char x;
    printTreeLevelWise(root);
    cout<<"\nx: ";
    cin>>x;
    findX(root, x) ? cout<<"True." : cout<<"False.";
}

template <typename T>
void printTreeLevelWise(TreeNode <T> *rootNode)
{
    if(rootNode == nullptr)
        return;
    
    queue <TreeNode <T> *> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <T> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->data<<": ";
        for(int i=0; i<subRoot->children.size(); i++)
        {
            cout<<subRoot->children[i]->data<<',';
            pendingNodes.push(subRoot->children[i]);
        }

        cout<<endl;
    }
}

template <typename T>
bool findX(TreeNode<T> *rootNode, T x)
{
    if(rootNode == nullptr)
        return false;
    
    if(rootNode->data == x)
        return true;

    for(int i=0; i<rootNode->children.size(); i++)
        if(findX(rootNode->children[i], x))
        {
            return true; 
        }

    return false;
}

template <typename T>
TreeNode <T>* createTree(T dataType_definer)
{
    T rootData;
    cout<<"root data: ";
    cin>>rootData;

    TreeNode <T> *rootNode = new TreeNode(rootData);
    queue <TreeNode<T>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode <T> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int noOfChildren;
        cout<<"no of children of "<<subRoot->data<<':';
        cin>>noOfChildren;

        for(int i=0; i<noOfChildren; i++)
        {
            T childData;
            cout<<"data of "<<i<<"th child of "<<subRoot->data<<':';
            cin>>childData;

            TreeNode <T> *childNode = new TreeNode(childData);

            subRoot->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return rootNode;
}