#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    for(int i=1; i<=n; i++) //rows
    {
        for(int j = 0; j < i; j++) //nos
        {
            cout<<j+1;
        }

        for(int j=0; j < (n-i)*2; j++) //spaces
        {
            cout<<" ";
        }

        for(int j=0; j< i; j++) //nos
        {
            cout<<i-j;
        }

        cout<<"\n";
    }
}