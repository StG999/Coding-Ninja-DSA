#include <iostream>

using namespace std;

void allIndex(int arr[], int size, int x, int output[], int *counter)
{
    cout<<*counter<<endl;
    if(size == 0)
        return;
    
    if(size == 1 && *arr == x)
    {
        output[*counter] = 0;
        *counter++;
        return;
    }
    else if(size == 1 && *arr != x)
        return;

    allIndex(arr, size - 1, x, output, counter);
    
    if(arr[size - 1] == x)
    {
        output[*counter] = size - 1;
        *counter++;
        return;
    }
}

int main(void)
{
    int size, x, counter = 0;
    cin>>size;

    int arr[size], output[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cin>>x;
    cout<<endl;

    allIndex(arr, size, x, output, &counter);

    cout<<endl;

    for(int i=0; i<counter; i++)
    {
        cout<<output[i]<<',';
    }
}