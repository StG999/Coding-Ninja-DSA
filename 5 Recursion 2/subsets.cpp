#include <iostream>
#include <cmath>

using namespace std;

int subsets(string arr[], int n, string output[])
{
    if(n == 0)
        return 1;
    
    int ans = subsets(arr + 1, n - 1, output);

    for(int i=0; i<ans; i++)
    {
        output[ans+i] = arr[0] + " " + output[i];
    }

    // for(int i=0; i<ans; i++)
    // {
    //     output[ans+i] = arr[0] + " " + output[ans + i];
    // }

    return ans*2;
}

int main(void)
{
    int n;
    cin>>n;

    string arr[n], output[int(pow(2, n))];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int size = subsets(arr, n, output);

    for(int i=0; i<size; i++)
    {
        cout<<output[i]<<endl;
    }
}