#include <iostream>

using namespace std;

int noOfDigits(long long n)
{
    if(n/10 == 0)
        return 1;
    
    return 1 + noOfDigits(n/10);
}

int main(void)
{
    long long n = 1213123121233;
    cout<<noOfDigits(n);
}