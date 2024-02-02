#include <iostream>
#include <cmath>

using namespace std;

int countZero(int n)
{
    int digits = int(log10(n)) + 1;
    if(digits == 1 && n%10 == 0)
        return 1;
    
    else if(digits == 1 && n%10 != 0)
        return 0;
    
    int ans = countZero(n / 10);

    if(n%10 == 0)
        return ans + 1;

    else
        return ans;

}

int main(void)
{
    int n;
    cin>>n;
    cout<<log10(n)<<endl;
    cout<<"output: "<<countZero(n);
}