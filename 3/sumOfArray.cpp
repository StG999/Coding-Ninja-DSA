#include <iostream>

using namespace std;

int sum(int arr[], int size)
{
    if(size == 0)
        return 0;
    
    else if(size == 1)
        return *arr;
    
    return arr[size-1] + sum(arr, size-1);
}

int main(void)
{
    int size;
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cout<<sum(arr, size);
}