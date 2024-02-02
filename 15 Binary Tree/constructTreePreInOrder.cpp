#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    
    BinaryTreeNode(T x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTreeNode<int>* createTree();
void printTree(BinaryTreeNode<int> *rootNode);
BinaryTreeNode<int>* createTreeInPreOrder(int inOrder[], int preOrder[], int n);
BinaryTreeNode<int>* createTreeInPreOrder_body(int inOrder[], int preOrder[], int inStart, int inEnd, int preStart, int preEnd);
int find(int arr[], int n, int x);

int main()
{
    int n;
    cin>>n;

    int *preOrder = new int[n];
    int *inOrder = new int[n];

    for(int i=0; i<n; i++)
        cin>>preOrder[i];

    for(int i=0; i<n; i++)
        cin>>inOrder[i];

    BinaryTreeNode<int> *root = createTreeInPreOrder(inOrder, preOrder, n);
    cout<<endl<<"here\n"<<endl;
    printTree(root);
}

int find(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
        if(arr[i] == x)
            return i;
        
    return -1;
}

BinaryTreeNode<int>* createTreeInPreOrder_body(int inOrder[], int preOrder[], int inStart, int inEnd, int preStart, int preEnd)
{
    if(inStart > inEnd || preStart > preEnd)
        return nullptr;

    int rootData = preOrder[preStart];
    BinaryTreeNode<int> *rootNode = new BinaryTreeNode<int>(rootData);

    int rootIndexInOrder = 0;
    for(int i=inStart; i<=inEnd; i++)
        if(rootData = inOrder[i])
        {
            rootIndexInOrder = i;
            break;
        }
    
    int inOrderSize = rootIndexInOrder - inStart;

    int lInS = inStart;
    int lInE = rootIndexInOrder - 1;
    int lPreS = preStart + 1;
    int lPreE = preStart + inOrderSize;
    int rIns = rootIndexInOrder + 1;
    int rInE = inEnd;
    int rPreS = preStart + inOrderSize + 1;
    int rPreE = preEnd;

    BinaryTreeNode<int> *leftChild = createTreeInPreOrder_body(inOrder, preOrder, lInS, lInE, lPreS, lPreE);
    BinaryTreeNode<int> *rightChild = createTreeInPreOrder_body(inOrder, preOrder, rIns, rInE, rPreS, rPreE);

    rootNode->left = leftChild;
    rootNode->right = rightChild;

    return rootNode;
}

BinaryTreeNode<int>* createTreeInPreOrder(int inOrder[], int preOrder[], int n)
{
    return createTreeInPreOrder_body(inOrder, preOrder, 0, n-1, 0, n-1);
}

void printTree(BinaryTreeNode<int> *rootNode)
{
    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->data<<':';
        if(subRoot->left != nullptr)
        {
            cout<<"L:"<<subRoot->left->data<<',';
            pendingNodes.push(subRoot->left);
        }

        if(subRoot->right != nullptr)
        {
            cout<<"R:"<<subRoot->right->data;
            pendingNodes.push(subRoot->right);
        }

        cout<<endl;
    }
}

BinaryTreeNode<int>* createTree()
{
    int rootData;
    cout<<"enter root data: ";
    cin>>rootData;

    BinaryTreeNode<int> *rootNode = new BinaryTreeNode(rootData);
    queue <BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int> *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int childData;
        cout<<"enter data of left child of "<<subRoot->data<<':';
        cin>>childData;

        if(childData != -1)
        {
            BinaryTreeNode<int> *childNode = new BinaryTreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->left = childNode;
        }

        cout<<"enter data of right child of "<<subRoot->data<<':';
        cin>>childData;

        if(childData != -1)
        {
            BinaryTreeNode<int> *childNode = new BinaryTreeNode(childData);
            pendingNodes.push(childNode);
            subRoot->right = childNode;
        }
    }

    return rootNode;
}