#include <iostream>
#include <math.h>

using namespace std;

int subsequences(string input, string output[])
{
    if(input.empty())
        return 1;

    int ans = subsequences(input.substr(1), output);

    for(int i=0; i<ans; i++)
    {
        output[i + ans] = input[0] + output[i];
    }
    
    return 2*ans;
}

int main(void)
{
    string input;
    cin>>input;

    string output[int(pow(2, input.length()))];
    int ans = subsequences(input, output);

    for(int i=0; i<ans; i++)
    {
        cout<<output[i]<<endl;
    }
}