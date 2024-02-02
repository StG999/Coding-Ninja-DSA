#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack <int> *stk);

int main()
{
    int n;
    cin>>n;

    stack <int> stack;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        stack.push(x);
    }

    reverseStack(&stack);

    for(int i=0; i<n; i++)
    {
        cout<<stack.top()<<' ';
        stack.pop();
    }
}

void reverseStack(stack <int> *stk)
{
    if((*stk).size() == 1)
        return;
    
    int top = (*stk).top();
    
    (*stk).pop();
    reverseStack(stk);
    
    stack <int> empty;
    while(!(*stk).empty())
    {
        empty.push((*stk).top());
        (*stk).pop();
    }

    (*stk).push(top);
    while(!empty.empty())
    {
        (*stk).push(empty.top());
        empty.pop();
    }
}