#include <iostream>

using namespace std;



int partition(int arr[], int start, int end)
{
    int pivot = start;
    for(int i=1; i<end-start+1; i++)
    {
        if(arr[start] > arr[i + start])
            pivot++;
    }

    swap(arr[start], arr[pivot]);

    int i = start, j = end;

    while(i < pivot && j > pivot)
    {
        while(arr[i] <= arr[pivot] && i < pivot)
            i++;
            
        while(arr[j] > arr[pivot] && j > pivot)
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
    
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int intersection(int input1[], int n1, int input2[], int n2, int output[])
{
    quickSort(input1, 0, n1-1);
    quickSort(input2, 0, n2-1);

    for(int i=0; i<n1; i++)
        cout<<input1[i]<<" ";
    
    cout<<endl;

    for(int i=0; i<n2; i++)
        cout<<input2[i]<<" ";

    cout<<endl;
    int i = 0, j = 0, counter = 0;

    if(n1 <= n2)
    {
        while(i < n1)
        {
            // cout<<"here\n";
            if(input1[i] == input2[i])
            {
                output[0] = input1[i];
                i++;
                j++;
                counter++;
            }

            else if(input1[i] < input2[i])
            {
                i++;
            }

            else if(input1[i] > input2[i])
            {
                j++;
            }
        }
    }

    
    
    // int counter = 1;

    // if(n1 <= n2)
    // {
    //     for(int i=0; i<n1; i++)
    //     {
    //         for(int j=0; input2[j] == input1[i]; j++)
    //             output[counter] = input1[i];
    //             counter++;
    //     }
    // }

    // if(n1 > n2)
    // {
    //     for(int i=0; i<n2; i++)
    //     {
    //         for(int j=0; input2[i] == input1[j]; j++)
    //             output[counter] = input1[j];
    //             counter++;
    //     }
    // }

    return counter;
}

int main(void)
{
    int t;
    cin>>t;

    int ans[t];
    // cout<<"here"<<endl;
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

        int output[min(n1, n2)];
        int size = intersection(input1, n1, input2, n2, output);
        // cout<<intersection(input1, n1, input2, n2, ans[i])<<endl;

        for(int i=0; i<size; i++)
            cout<<output[i]<<" ";
    }



    // for(int i=0; i<t; i++)
    // {
    //     for(int j=1; j<ans[i][0]; j++)
    //         cout<<ans[i][j];
    //         cout<<"here";
    // }

    // int n;
    // cin>>n;

    // int arr[n];
    // for(int i=0; i<n; i++)
    //     cin>>arr[i];
    
    // quickSort(arr, 0, n-1);

    // for(int i=0; i<n; i++)
    //     cout<<arr[i]<<" ";
}