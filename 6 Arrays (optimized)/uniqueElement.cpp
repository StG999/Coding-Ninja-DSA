#include <iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int tmp[end - start + 1], i = start, j = mid + 1, counter = 0;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            tmp[counter] = arr[i];
            i++;
            counter++;
        }

        else
        {
            tmp[counter] = arr[j];
            j++;
            counter++;
        }
    }

    while(i <= mid)
    {
        tmp[counter] = arr[i];
        i++;
        counter++;
    }

    while(j <= end)
    {
        tmp[counter] = arr[j];
        j++;
        counter++;
    }

    for(int i=0; i<end-start+1; i++)
        arr[start + i] = tmp[i];
}

void mergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;
    
    int mid = (start + end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int uniqueElement(int input[], int size)                                    // TIME COMPLEXITY IS N*logN
{
    mergeSort(input, 0, size-1);

    if(input[0] != input[1])
        return input[0];
    
    for(int i=2; i<size; i+=2)
        if(input[i] != input[i+1])
            return input[i];
        
    return input[size-1];
}

int main()
{
    int t;
    cin>>t;
    int ans[t];

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        int input[n];
        for(int j=0; j<n; j++)
            cin>>input[j];
        
        ans[i] = uniqueElement(input, n);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;
}