#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printTree(TreeNode *rootNode)
{
    queue <TreeNode*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode *subRoot = pendingNodes.front();
        pendingNodes.pop();

        cout<<subRoot->val<<':';
        if(subRoot->left != nullptr)
        {
            cout<<"L:"<<subRoot->left->val<<',';
            pendingNodes.push(subRoot->left);
        }

        if(subRoot->right != nullptr)
        {
            cout<<"R:"<<subRoot->right->val;
            pendingNodes.push(subRoot->right);
        }

        cout<<endl;
    }
}

TreeNode* createTree()
{
    int rootval;
    cout<<"enter root val: ";
    cin>>rootval;

    TreeNode *rootNode = new TreeNode(rootval);
    queue <TreeNode*> pendingNodes;
    pendingNodes.push(rootNode);

    while(!pendingNodes.empty())
    {
        TreeNode *subRoot = pendingNodes.front();
        pendingNodes.pop();

        int childval;
        cout<<"enter val of left child of "<<subRoot->val<<':';
        cin>>childval;

        if(childval != -1)
        {
            TreeNode *childNode = new TreeNode(childval);
            pendingNodes.push(childNode);
            subRoot->left = childNode;
        }

        cout<<"enter val of right child of "<<subRoot->val<<':';
        cin>>childval;

        if(childval != -1)
        {
            TreeNode *childNode = new TreeNode(childval);
            pendingNodes.push(childNode);
            subRoot->right = childNode;
        }
    }

    return rootNode;
}

// class Solution {
// public:
    int heightBST(TreeNode *root)
    {
        if(root == NULL)
            return 0;
            
        return 1 + max(heightBST(root->left), heightBST(root->right));
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL)
            return NULL;

        root->left = balanceBST(root->left);
        root->right = balanceBST(root->right);

        if(heightBST(root->right) > heightBST(root->left) + 1)
        {
            TreeNode *tmpRL = root->right->left;
            TreeNode *tmpR = root->right;

            tmpR->left = root;
            root = tmpR;
            tmpR = tmpR->left;

            while(tmpR->right != NULL)
                tmpR = tmpR->right;

            tmpR->right = tmpRL;
        }

        return root;
    }
// };

int find(vector<int> &arr, int val, int start, int end)
    {
        for(int i=start; i<end; i++)
        {
            if(arr[i] > val)
                return i;
        }

        return -1;
    }

    TreeNode* func(vector<int> &arr, int start, int end)
    {
        if(start > end)
            return NULL;
        
        TreeNode *root = new TreeNode(arr[start]);

        int rightStart = find(arr, arr[start], start, end);

        root->left = func(arr, start+1, rightStart-1);
        root->right = func(arr, rightStart, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder, 0, preorder.size()-1);
    }

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> output;
        vector<int> arr = nums;
        unordered_map <int, int> map;
        sort(arr.begin(), arr.end());

        for(int i=arr.size()-1; i>=0; i--)
        {
            int j = i;
            while(i > 0 && arr[j] == arr[j-1])
                j--;
            
            map[arr[i]] = j;
            i = j;
        }

        for(int i=0; i<nums.size(); i++)
            output.push_back(map[nums[i]]);
        
        return output;
    }


ListNode* createList(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for(int i=1; i<n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void printList(ListNode *head)
{
    while(head != NULL)
    {
        cout<<head->val<<',';
        head = head->next;
    }

    cout<<endl;
}

TreeNode* sortedListToBST(ListNode* head) 
{
    if(head == NULL)
        return NULL;
    
    ListNode *slow = head, *fast = head, *prev = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *newHead = new TreeNode(slow->val);
    if(prev != NULL)
        prev->next = NULL;

    if(prev == NULL)    
        newHead->left = sortedListToBST(prev);
    else
        newHead->left = sortedListToBST(head);

    newHead->right = sortedListToBST(slow->next);

    return newHead;
}

void inOrder(TreeNode *root, vector<int> *arr)
    {
        if(root == NULL)
        {
            arr->push_back(-1);
            return;
        }
        inOrder(root->left, arr);
        arr->push_back(root->val);
        inOrder(root->right, arr);
    }

void rtlpath(TreeNode *root, vector<string> &arr, string output)
    {
        if(root->left == NULL && root->right == NULL)
        {
            output = output + char(root->val + '0');
            cout<<"hereQ"<<output<<endl;
            arr.push_back(output);
            return;
        }
        
        output = output + char(root->val + '0');
        cout<<"here"<<output<<endl;
        rtlpath(root->left, arr, output);
        rtlpath(root->right, arr, output);
    }

vector<int> BFS(TreeNode *root)
{
    vector<int> arr;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *top = q.front();
        q.pop();
        if(top != NULL)
            arr.push_back(top->val);
        else
        {
            arr.push_back(-1);
            continue;
        }
        if(top->left != NULL || top->right != NULL)
        {
            q.push(top->left);
            q.push(top->right);
        }
    }

    return arr;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(head == NULL)
        return NULL;

    ListNode *current = head;
    stack<ListNode*> stk;
    for(int i=0; i<k; i++)
    {
        cout<<"here"<<current->val<<endl;
        if(current == NULL)
            return head;
        stk.push(current);
        current = current->next;
    }
    
    cout<<"hereQ"<<endl;
    head = stk.top();
    getchar();
    current = head;
    ListNode *nextHead = current->next;
    stk.pop();
    for(int i=1; i<k; i++)
    {
        cout<<"here"<<current->val<<endl;
        current->next = stk.top();
        stk.pop();
        current = current->next;
    }
    getchar();

    current->next = reverseKGroup(nextHead, k);

    return head;
}

TreeNode *f(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    root->val = 1;
    while (!q.empty())
    {
        TreeNode *top = q.front();
        q.pop();
        if (top->left)
        {
            top->left->val = (top->val - 1) * 2 + 1;
            q.push(top->left);
        }

        if (top->right)
        {
            top->right->val = (top->val - 1) * 2 + 2;
            q.push(top->right);
        }
    }
    return root;
}

int main()
{
    // TreeNode *root = createTree();
    // root = f(root);
    // cout<<endl;
    // printTree(root);
    string s = "abcdef";
    cout<<s.substr(1,3);
}