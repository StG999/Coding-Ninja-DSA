#include <iostream>
#include <cmath>

using namespace std;

int permutations(string input, string output[])
{
    if(input.empty())
        return 1;
    
    cout<<"here\n";
    int ans = 0;
    for(int i=0; i<input.length(); i++)
    {
        string erased = input.substr(i, 1);
        string tmp = input;
        tmp.erase(i, 1);
        
        int prevAns = ans;

        int ans = permutations(tmp, output + ans) + ans;

        for(int j=prevAns; j<ans; j++)
            output[j] = erased + " " + output[j];
    }

    return ans;
}

int main(void)
{
    string input;
    cin>>input;
    
    string output[int(tgamma(input.length() + 1))];                  // tgamma(i) = (i-1)!

    int ans = permutations(input, output);

    for(int i=0; i<ans; i++)
        cout<<output[i]<<endl;
}