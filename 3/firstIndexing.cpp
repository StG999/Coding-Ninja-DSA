#include <iostream>

using namespace std;

int firstIndex(int arr[], int size, int x)
{
    if(size == 0)
        return -1;
    
    else if(size == 1 && *arr == x)
        return 0;
    else if(size == 1 && *arr != x)
        return -1;
    
    if(arr[size - 1] == x && firstIndex(arr, size - 1, x) == -1)
        return size - 1;
    else
        return firstIndex(arr, size - 1, x);
}

int main(void)
{
    int size, x;
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cin>>x;

    cout<<"Index: "<<firstIndex(arr, size, x);
}