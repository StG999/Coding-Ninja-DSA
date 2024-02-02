#include <iostream>

using namespace std;

int sum(int arr[], int n)
{
    int ans = 0;
    for(int i=0; i<n; i++)
        ans += arr[i];
    
    return ans;
}

bool splitArray(int arr[], int n, int arr3[], int arr5[])
{
    if(n < 2)
        return false;
    
    bool ans = splitArray(arr+1, n-1, arr3, arr5);


}

int main(void)
{
    int n;
    cin>>n;

    int arr[n], arr3[n] = {0}, arr5[n] = {0};
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    splitArray(arr, n, arr3, arr5) ? cout<<"True" : cout<<"False";
}