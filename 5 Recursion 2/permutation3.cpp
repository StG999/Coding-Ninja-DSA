#include <iostream>
#include <cmath>

using namespace std;

int permutations(string input, string output[])
{
    if(input.empty())
        return 1;
    
    int ans[input.length()];
    string erased[input.length()];
    string permutation[input.length()][int(tgamma(input.length()))];

    for(int i=0; i<input.length(); i++)
        erased[i] = input.substr(i, 1);
    
    for(int i=0; i<input.length(); i++)
    {
        string tmp = input;
        tmp.erase(i, 1);

        ans[i] = permutations(tmp, permutation[i]);
    }

    for(int i=0; i<input.length(); i++)
    {
        for(int j=0; j<int(tgamma(input.length())); j++)
            output[i*int(tgamma(input.length())) + j] = erased[i] + " " + permutation[i][j];
    }

    return int(tgamma(input.length()));
}

int main(void)
{
    string input;
    cin>>input;
    string output[int(tgamma(input.length() + 1))];

    int ans = permutations(input, output);

    for(int i=0; i<ans; i++)
        cout<<output[i]<<endl;
}