#include <iostream>

using namespace std;

void printSubset(string input[], int n, string output)
{
    if(n == 0)
    {
        cout<<output<<endl;
        return;
    }

    printSubset(input + 1, n-1, output);
    printSubset(input + 1, n-1, output + " " + input[0]);
}

int main(void)
{
    int n;
    cin>>n;

    string input[n], output = "";

    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    printSubset(input, n, output);
}