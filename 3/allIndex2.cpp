#include <iostream>

using namespace std;

int allIndex(int arr[], int size, int x, int output[])
{
    if(size == 0)
        return 0;
    
    if(size == 1 && *arr == x)
    {
        output[0] = 0;
        return 1;
    }
    else if(size == 1 && *arr != x)
        return 0;
    
    int ans = allIndex(arr, size - 1, x, output);

    if(arr[size - 1] == x)
    {
        output[ans] = size - 1;
        return 1 + ans;
    }
    
    else
        return ans;
}

int main(void)
{
    int size,x;
    cin>>size;

    int arr[size], output[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    
    cin>>x;

    cout<<endl;
    int ans = allIndex(arr, size, x, output);

    for(int i=0; i<ans; i++)
    {
        cout<<output[i]<<" ";
    }
}