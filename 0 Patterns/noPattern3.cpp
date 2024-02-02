#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout<<"n: ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i <= (n+1)/2)
            {
                cout<<((i-1)*(2*n) + j);
                cout<<" ";
            }

            else
            {
                cout<<(n-i)*2*n + n + j;
                cout<<" ";
            }
        }

        cout<<"\n";
    }
}