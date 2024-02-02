#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigits(int n)
{
    int digits = log10(n) + 1;

    if(digits == 1)
        return n;
    
    int ans = sumOfDigits(n/10);

    return ans + n%10;
}

int main(void)
{
    int n;
    cin>>n;

    cout<<"Sum: "<<sumOfDigits(n);
}