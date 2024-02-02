#include <iostream>

using namespace std;

int duplicate(int input[], int size)
{
    int sum = (size-2)*(size-1)/2;

    int sumOfArr = 0;
    for(int i=0; i<size; i++)
        sumOfArr += input[i];
    
    return sumOfArr - sum;
}

int main()
{
    int t;
    cin>>t;

    int ans[t];

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        int input[n];

        for(int j=0; j<n; j++)
            cin>>input[j];
        
        ans[i] = duplicate(input, n);
        // cout<<ans[i]<<endl;
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}