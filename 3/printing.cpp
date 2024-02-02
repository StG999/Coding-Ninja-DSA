#include <iostream>

using namespace std;

void print(int n)
{
    if(n == 1)
    {
        cout<<1<<endl;
        return;
    }

    print(n-1);
    cout<<n<<endl;
    return;
}

int main(void)
{
    int n = 5;

    print(n);
}