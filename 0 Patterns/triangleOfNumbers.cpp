#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    for(int i = 0; i < n; i++) //rows
    {
        for(int j=0; j< n-i-1; j++) //spaces
        {
            cout<<" ";
        }

        for(int j=0; j< i+1; j++) //inc no.
        {
            cout<<i+j+1;
        }
        
        for(int j=0; j<i; j++) //dec no
        {
            cout<< 2*(i) - j;
        }

        cout<<"\n";
    }
}