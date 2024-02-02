#include <iostream>

using namespace std;

int oddOccurences(int arr[], int n)
{
    int hash[INT16_MAX];
    
    for(int i=0; i<n; i++)
        hash[arr[i]]++;
    
    for(int i=0; i<INT16_MAX; i++)
        if(hash[i] % 2 == 1)
            return i;

    return -1;
}

int main(void)
{
    int t;
    cin>>t;
    int ans[1000];

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        int arr[100000];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        
        ans[i] = oddOccurences(arr, n);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}