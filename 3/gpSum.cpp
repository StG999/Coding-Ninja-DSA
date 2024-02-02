#include <iostream>
#include <cmath>

using namespace std;

float gpSum(int k)
{
    // 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
    if(k == 0)
        return 1;
    
    return gpSum(k-1) + 1/pow(2, k);
}

int main(void)
{
    int k;
    cin>>k;

    cout<<"Geometric Sum: "<<gpSum(k);
}