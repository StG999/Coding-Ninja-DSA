#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    for(int i = 1; i<=n; i++) //rows
    {
        if(i <= (n+1)/2)
        {
            for(int j=0; j<i-1; j++) //spaces
            {
                cout<<" ";
            }

            for(int j=0; j< i; j++) //*
            {
                cout<<"* ";
            }
        }

        else
        {
            for(int j=0; j< n-i;j++) //spces
            {
                cout<<" ";
            }

            for(int j=0; j < n-i+1; j++) //*
            {
                cout<<"* ";
            }
        }

        cout<<"\n";
    }
}