#include <iostream>

using namespace std;

void mergeSort(int arr[], int startIndex, int endIndex)
{
    if(startIndex >= endIndex)
        return;

    int mid = (startIndex+endIndex)/2;

    mergeSort(arr, startIndex, mid);
    mergeSort(arr, mid + 1, endIndex);

    int tmp[endIndex - startIndex + 1];
    int i = startIndex, j = mid + 1, counter = 0;

    while(i != mid + 1 && j != endIndex + 1)
    {
        // JAB I OR J MID +1 KE BARABAR HO JAAYE TOH SEEDHA DOOSRA VAALA COPY KARDO NO NEED FOR COMPARISON KYUKI GARBAGE VALUE SE HOGA COMPARISON
        if(arr[i] > arr[j])
        {
            tmp[counter] = arr[j];
            j++;
            counter++;
            continue;
        }

        else
        {
            tmp[counter] = arr[i];
            i++;
            counter++;
            continue;
        }
    }

    if(i == mid + 1)
    {
        while(j != endIndex + 1)
        {
            tmp[counter] = arr[j];
            counter++;
            j++;
        }
    }

    else if(j == endIndex + 1)
    {
        while(i != mid + 1)
        {
            tmp[counter] = arr[i];
            counter++;
            i++;
        }
    }

    for(int i=0; i<endIndex - startIndex + 1; i++)
    {
        cout<<tmp[i] << " ";
    }

    cout<<endl;

    for(int i=0; i<endIndex - startIndex + 1; i++)
    {
        arr[i] = tmp[i];
    }

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

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}