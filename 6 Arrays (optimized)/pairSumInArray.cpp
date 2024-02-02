#include <iostream>

using namespace std;

int partition2(int arr[], int start, int end)
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

int partition(int arr[], int start, int end)
{
    int pivot = start;

    for(int i=1; i<end-start+1; i++)
    {
        if(arr[start + i] < arr[start])
            pivot++;
    }

    swap(arr[start], arr[pivot]);

    int i = start, j = end;
    while(i < pivot && j > pivot)
    {
        while(arr[pivot] > arr[i])
            i++;

        while(arr[pivot] <= arr[j])
            j--;
        
        // if(i < pivot && j > pivot)
        // {
        swap(arr[i], arr[j]);
        i++;
        j--;
        // }
    }

    return pivot;
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end)
        return;
    
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int pairSum(int arr[], int n, int x)
{
    quickSort(arr, 0, n-1);

    int i = 0, j = n-1, ans = 0;

    // FOR ALL SAME ELEMENTS
    if(arr[0] == arr[n-1] && x == 2*arr[0])
        return n*(n-1)/2;


    while(i < j)
    {
        if(arr[i] + arr[j] == x)
        {
            int copyI = 0, copyJ = 0;

            do
            {
                copyI++;
                i++;
            }while(arr[i] == arr[i - 1] && i < j);
            
            do
            {
                copyJ++;
                j--;
            }while(arr[j] == arr[j + 1] && i - 1 < j);

            ans += copyI*copyJ;
        }

        else if(arr[i] + arr[j] > x)
            j--;

        else if(arr[i] + arr[j] < x)
            i++;
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    int ans[t];

    for(int i=0; i<t; i++)
    {
        int n, x;
        cin>>n;

        int arr[n];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        
        cin>>x;

        ans[i] = pairSum(arr, n, x);

        // for(int i=0; i<n; i++)
        //     cout<<arr[i]<<" ";
        
        // cout<<endl;
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;

    // int n;
    // cin>>n;

    // int arr[n];
    // for(int i=0; i<n; i++)
    //     cin>>arr[i];

    // quickSort(arr, 0, n-1);

    // for(int i=0; i<n; i++)
    //     cout<<arr[i]<<" ";
}