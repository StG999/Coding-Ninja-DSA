#include <iostream>

using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start+end)/2;
    int i = start, j = mid + 1, k = 0;

    int tmp[end - start + 1];

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }

        else
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }
    }

    // if(i > mid)
    // {
        while(j <= end)
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }
    // }

    // else if(j > end)
    // {
        while(i <= mid)
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }
    // }

    for(int z=0; z<end-start+1; z++)
    {
        arr[start + z] = tmp[z];
    }

    return;
}

void mergeSort(int arr[], int start, int end)
{
    // cout<<"mergeSort Begins****";
    if(start >= end)
        return;
    
    int mid = (start+end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);

    // for(int i=0; i<end-start+1; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    return;
}

int main(void)
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i <n; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}