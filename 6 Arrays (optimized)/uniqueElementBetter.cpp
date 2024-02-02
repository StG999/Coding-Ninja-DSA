#include <iostream>

using namespace std;

int uniqueElement(int input[], int n)                           // TIME COMPLEXITY IS N^2
{
    int ans = input[0];
    
    for(int i=1; i<n; i++)
    {
        ans = ans ^ input[i];
    }

    return ans;
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
        
        ans[i] = uniqueElement(input, n);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}