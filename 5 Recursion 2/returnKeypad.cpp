#include <iostream>
#include <cmath>

using namespace std;

string combos[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int returnKeypad(int input, string output[])
{
    if(input == 0)
        return 1;
    
    int ans = returnKeypad(input / 10, output);


    for(int i=1; i<combos[input%10-2].length(); i++)
    {
        for(int j=0; j<ans; j++)
        {
            output[ans*(i) + j] = output[j];
        }
    }

    for(int i=0; i<combos[input%10-2].length(); i++)
    {
        for(int j=0; j<ans; j++)
        {
            output[ans*(i) + j] = output[ans*(i) + j] + combos[input%10-2][i];
        }
    }

    return combos[input%10].length() * ans;
}

int main(void)
{
    int input;
    cin>>input;
    
    string output[int(pow(4, log10(input) + 1))];

    int ans = returnKeypad(input, output);

    for(int i=0; i<ans; i++)
    {
        cout<<output[i]<<endl;
    }
}