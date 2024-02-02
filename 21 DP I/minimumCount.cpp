#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int func2(int n, int *arr)
{
    if(arr[n] != -1)
        return arr[n];
    
    vector <int> ans;
    int i = 1;

    while(i*i <= n)
    {
        ans.push_back(func2(n-i*i, arr));
        i++;
    }

    int min = *min_element (ans.begin(), ans.end()) + 1;
    arr[n] = min;

    return min;
}

int func(int n)
{
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++)
        arr[i] = -1;
    
    arr[1] = 1;
    arr[0] = 0;

    return func2(n, arr);
}

int main()
{
    cout<<func(13)<<endl;
}