#include <iostream>

using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = start;
    for(int i=1; i<end-start+1; i++){
        if(arr[i + start] < arr[start])
            pivot++;
    }
    
    swap(arr[pivot], arr[start]);

    int i = start, j = end;
    while(i < pivot && j > pivot)
    {
        while(arr[i] <= arr[pivot])
            i++;
            
        while(arr[j] > arr[pivot])
            j--;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return pivot;
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end)
        return;
    
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

int maxProfit(int arr[], int n)
{
    quickSort(arr, 0, n-1);
    int max = arr[0]*n;
    
    for(int i=1; i<n; i++)
        if(arr[i]*(n-i) > max)
            max = arr[i]*(n-i);

    return max;

}

int main(void)
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<maxProfit(arr, n);
    // quickSort(arr, 0, n-1);
    // for(int i=0; i<n; i++)
    //     cout<<arr[i]<<" ";
}