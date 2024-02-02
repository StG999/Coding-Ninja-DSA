#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], int start, int end)
{
    int n = end - start + 1, pivot = start;

    for(int i=1; i<n; i++)
    {
        if(arr[start] > arr[start + i])
            pivot++;
    }

    swap(arr[start], arr[pivot]);

    int i = start, j = end;
    
    while(i < pivot && j > pivot)
    {
        while(arr[i] < arr[pivot])
            i++;

        while(arr[j] >= arr[pivot])
            j--;

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return pivot;
}

void quickSort(int arr[], int start, int end)
{
    if(end <= start)
        return;
    
    int pivot = partition(arr, start, end);
    
    quickSort(arr, start, pivot - 1);

    quickSort(arr, pivot + 1, end);

    return;
}

int main(void)
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}