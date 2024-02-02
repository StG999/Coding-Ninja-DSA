#include <iostream>
#include <cmath>

using namespace std;

string combos[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", 
    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int allCodes(string input, string output[])
{
    if(input.empty())
        return 1;
    
    int ans = allCodes(input.substr(1), output);

    for(int i=0; i<ans; i++)
        output[i] = combos[int(input[0]) - 49] + " " + output[i];
    
    if(input.length() > 1 && stoi(input.substr(0, 2)) <= 26)
    {    
        int ans2 = allCodes(input.substr(2), output + ans);
        for(int i=0; i<ans2; i++)
            output[ans + i] = combos[stoi(input.substr(0, 2)) - 1] + " " + output[ans + i];

        return ans + ans2;
    }

    return ans;
}   

int main(void)
{
    string input, output[int(pow(2, input.length()))];
    cin>>input;

    int ans = allCodes(input, output);

    for(int i=0; i<ans; i++)
        cout<<output[i]<<endl;
}