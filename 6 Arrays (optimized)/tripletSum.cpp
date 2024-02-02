#include <iostream>

using namespace std;

void mergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int mid = (start + end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int tmp[end - start + 1];
    int i = start, j = mid + 1, counter = 0;

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
        arr[i + start] = tmp[i];
}

int tripletSum(int arr[], int n, int x)
{
    if (n < 3)
        return 0;
    
    mergeSort(arr, 0, n-1);

    int i = 0, j = n-1, ans = 0;

    while(i < n - 2)
    {
        int k = i + 1;
        
        while(i + 1 < j)
        {
            if(arr[i] + arr[k] + arr[j] == x && k != j)
            {
                ans++;
                
                while(arr[k+1] == arr[k])
                {
                    ans++;
                    k++;
                }
                j--;
                k = i + 1;
            }

            else if(arr[i] + arr[k] + arr[j] < x && k < j)
                k++;
            
            else
            {
                j--;
                k = i + 1;
            }
            // else if(arr[i] + arr[k] + arr[j] > x)
            //     j--;
        }

        i++;
        j = n-1;
    }

    return ans;
}

int main(void)
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

        ans[i] = tripletSum(arr, n, x);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i]<<endl;

    // int n;
    // cin>>n;
    // int arr[n];

    // for(int i=0; i<n; i++)
    //     cin>>arr[i];
    
    // mergeSort(arr, 0, n-1);

    // for(int i=0; i<n; i++)
    //     cout<<arr[i]<<" ";

}