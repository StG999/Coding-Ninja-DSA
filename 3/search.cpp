#include <iostream>

using namespace std;

bool find(int arr[], int size, int x)
{
    if (size==0)
        return false;
    
    if(size == 1 && *arr == x)
        return true;
    else if(size == 1 && *arr != x)
        return false;
    
    // return (arr[size-1] == x && find(arr, size - 1, x));
    if(arr[size - 1] == x || find(arr, size-1, x))
        return true;
    else
        return false;
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

    if(find(arr, size, x))
        cout<<"True";
    else
        cout<<"False";
}