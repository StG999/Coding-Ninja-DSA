#include <iostream>

using namespace std;

void towerOfHanoi(int n, char S, char A, char D)
{
    if(n == 0)
        return;

    towerOfHanoi(n-1, S, D, A);

    cout<<S<<" -> "<<D<<endl;

    towerOfHanoi(n-1, A, S, D);
}

int main(void)
{
    int n;
    char S = 'a', A = 'b', D = 'c';
    cin>>n;
    cout<<"-------"<<endl;

    towerOfHanoi(n, S, A, D);
}