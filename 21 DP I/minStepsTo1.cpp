#include <iostream>
using namespace std;

int func(int n, int *arr)
{
    if(arr[n] != -1)
        return arr[n];
    
    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if(n%3 == 0)
        ans1 = func(n/3, arr);

    if(n%2 == 0)
        ans2 = func(n/2, arr);

    ans3 = func(n-1, arr);

    arr[n] =  min(ans1, min(ans2, ans3)) + 1;

    return arr[n];
}

int func1(int n)
{
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++)
        arr[i] = -1;
    
    arr[1] = 0;
    return func(n, arr);
}

int main()
{
    cout<<func1(11);
}