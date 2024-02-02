#include <iostream>
#include <cmath>

using namespace std;

int subsetsSumToK(string input[], int n, string output[], int k)
{
    if(n == 0 && k == 0)
        return 1;
    else if(n == 0 && k != 0)
        return 0;
    
    int ans = subsetsSumToK(input + 1, n - 1, output, k - stoi(input[0]));
    
    int ans2 = subsetsSumToK(input + 1, n - 1, output + ans, k);

    for(int i=0; i<ans; i++)
        output[i] = input[0] + " " + output[i];

    return ans + ans2;
}

int main(void)
{
    int n, k;
    cin>>n;

    string input[n], output[int(pow(2, n/2))];
    for(int i=0; i<n; i++)
        cin>>input[i];

    cin>>k;

    int ans = subsetsSumToK(input, n, output, k);

    for(int i=0; i<ans; i++)
        cout<<output[i]<<endl;
}