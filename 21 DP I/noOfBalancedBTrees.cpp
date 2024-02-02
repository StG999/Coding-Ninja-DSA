#include <iostream>

using namespace std;

int func(int h, int *arr)
{
    if(arr[h] != 0)
        return arr[h];
    
    if(h <= 1)
        return 1;
    
    int h1 = func(h-1, arr);
    int h2 = func(h-2, arr);

    arr[h] = h1*h1 + h1*h2*2;
    return arr[h];
}

int funcDP(int h, int *arr)
{
    arr[0] = 1;
    arr[1] = 1;

    for(int i=2; i<=h; i++)
        arr[i] = arr[i-1]*arr[i-1] + 2*arr[i-1]*arr[i-2];
    
    return arr[h];
}

int main()
{
    int n = 4;
    int ans[n+1] = {0};
    cout<<funcDP(n, ans);
}