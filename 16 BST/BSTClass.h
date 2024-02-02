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

class BST
{
    BinaryTreeNode<int> *root;

    public:
        BST()
        {
            this->root = nullptr;
        }

    private:
        bool searchNode(int value, BinaryTreeNode<int> *node)
        {
            if(node == nullptr)
                return false;
            
            if(node->data == value)
                return true;
            
            if(node->data > value)
                return searchNode(value, node->left);

            else
                return searchNode(value, node->right);
        }

    public:
        bool searchNode(int value)
        {
            return searchNode(value, root);
        }
    
    private:
        BinaryTreeNode<int>* insertNode(int value, BinaryTreeNode<int> *root)
        {
            if(root == nullptr)
                return (new BinaryTreeNode(value));

            if(value > root->data)
                root->right = insertNode(value, root->right);
            
            else
                root->left = insertNode(value, root->left);
            
            return root;
        }

    public:
        void insertNode(int value)
        {
            root = insertNode(value, root);
        }
    
    private:
        BinaryTreeNode<int>* deleteNode(int value, BinaryTreeNode<int> *root)
        {
            if(root == nullptr)
                return nullptr;

            if(value > root->data)
                root->right = deleteNode(value, root->right);

            else if(value < root->data)
                root->left = deleteNode(value, root->left);
            
            else
            {
                if(root->left == nullptr)
                {
                    BinaryTreeNode<int> *newRoot = root->right;
                    delete root;
                    return newRoot;
                }

                else if(root->right == nullptr)
                {
                    BinaryTreeNode<int> *newRoot = root->left;
                    delete root;
                    return newRoot;
                }

                else
                {
                    BinaryTreeNode<int> *newRoot = root->right;
                    while(newRoot->left != nullptr)
                        newRoot = newRoot->left;
                    
                    root->data = newRoot->data;
                    root->right = deleteNode(root->data, root->right);
                }
            }
            
            return root;
        }

    public:
        void deleteNode(int value)
        {
            root = deleteNode(value, root);
        }
    
    public:
        void printTree()
        {
            queue <BinaryTreeNode<int>*> pendingNodes;
            if(root != nullptr)
                pendingNodes.push(root);

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

        void increasingBST()
        {
            root = increasingBST(root);
        }

    private:
        BinaryTreeNode<int>* increasingBST(BinaryTreeNode<int> *root)
        {
            if(root == nullptr)
                return nullptr;
            
            if(root->left == NULL)
                return root;
            
            if(root->right == NULL)
            {
                BinaryTreeNode<int> *ans = increasingBST(root->left);
                BinaryTreeNode<int> *tmp = ans;
                while(tmp->right != nullptr)
                    tmp = tmp->right;
                
                tmp->right = root;
                root->left = nullptr;

                return ans;
            }

            BinaryTreeNode<int> *leftAns = increasingBST(root->left);
            root->right = increasingBST(root->right);

            BinaryTreeNode<int> *tmp = leftAns;
            while(tmp->right != nullptr)
                tmp = tmp->right;
            
            tmp->right = root;
            root->left = nullptr;
            
            return leftAns;
        }
};