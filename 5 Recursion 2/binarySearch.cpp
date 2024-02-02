#include <iostream>

using namespace std;

int binarySeach(int arr[], int start, int end, int x)
{
    if(start == end && arr[start] != x)
        return -1;
    
    // else if(start == end && arr[start] == x)
    //     return start;

    int mid = (start + end)/2;
    // cout<<mid<<endl;

    if(arr[mid] == x)
        return mid;
    
    else if(arr[mid] > x)
        return binarySeach(arr, start, mid, x);
    
    else if(arr[mid] < x)
        return binarySeach(arr, mid + 1, end, x);

    return -1;

}

int main(void)
{
    int n, x;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cin>>x;

    cout<<binarySeach(arr, 0, n-1, x);
}