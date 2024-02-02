#include <iostream>

using namespace std;

void printSubsetsSumToK(string input[], int n, int k, string output)
{
    if(n == 0 && k == 0)
    {
        cout<<output<<endl;
        return;
    }

    if(n == 0 && k != 0)
        return;
    if(n > 0)
        printSubsetsSumToK(input + 1, n - 1, k - stoi(input[0]), output + " " + input[0]);
    
    printSubsetsSumToK(input + 1, n - 1, k, output);
}

int main(void)
{
    int n, k;
    cin>>n;

    string input[n], output;
    for(int i=0; i<n; i++)
        cin>>input[i];

    cin>>k;

    printSubsetsSumToK(input, n, k, output);
}