#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    for(int i=1; i<=n; i++)     //rows
    {
        for(int j=0; j<n-i; j++)       //spaces
        {
            cout<<" ";
        }

        for(int j=0; j< i; j++)
        {
            cout<<i+j;
        }

        cout<<"\n";
    }
}