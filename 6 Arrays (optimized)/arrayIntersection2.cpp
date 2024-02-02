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
        while(arr[i] < arr[pivot] && i < pivot)
        {
            i++;
        }

        while(arr[j] >= arr[pivot] && j > pivot)
        {
            j--;
        }

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

int intersection(int arr1[], int n1, int arr2[], int n2, int output[])
{
    quickSort(arr1, 0, n1-1);
    quickSort(arr2, 0, n2-1);

    int i=0, j=0, ans=0;

    while(i < n1 && j < n2)
    {
        if(arr1[i] == arr2[j])
        {
            output[ans] = arr1[i];
            ans++;
            i++;
            j++;
        }

        else if(arr1[i] < arr2[j])
        {
            i++;
        }

        else if(arr1[i] > arr2[j])
        {
            j++;
        }
    }

    return ans;
}

int main(void)
{
    int t;
    cin>>t;

    int ans[t], output[t][100];

    for(int i=0; i<t; i++)
    {
        int n1, n2;

        cin>>n1;
        int input1[n1];

        for(int j=0; j<n1; j++)
            cin>>input1[j];

        cin>>n2;
        int input2[n2];

        for(int j=0; j<n2; j++)
            cin>>input2[j];

        ans[i] = intersection(input1, n1, input2, n2, output[i]);
    }

    for(int i=0; i<t; i++)
    {
        for(int j=0; j<ans[i]; j++)
            cout<<output[i][j]<<" ";
        
        cout<<endl;
    }

    // int arr[] = {4, 2, 1, 6, 3, 1};
    // quickSort(arr, 0, 5);

    // for(int i=0; i<6; i++)
    //     cout<<arr[i]<<" ";
}