#include <iostream>
#include <stack>

using namespace std;

int* stockSpan(int prices[], int n, int span[]);

int main()
{
    int n;
    cin>>n;
    int *prices = new int[n];
    int *span = new int[n];

    for(int i=0; i<n; i++)
        cin>>prices[i];
    
    span = stockSpan(prices, n, span);

    for(int i=0; i<n; i++)
        cout<<span[i]<<' ';
}

int* stockSpan(int prices[], int n, int span[])
{
    stack <int> stack;
    int count;

    for(int i=0; i<n; i++)
    {
        count = 1;

        if(stack.empty() || stack.top() >= prices[i])
        {
            stack.push(prices[i]);
            span[i] = count;
            continue;
        }

        while(!stack.empty() && stack.top() < prices[i])
        {
            stack.pop();
            count++;
        }

        if(stack.empty())
        {
            span[i] = i+1;
            stack.push(prices[i]);
            continue;
        }

        span[i] = count;
        stack.push(prices[i]);
    }

    return span;
}