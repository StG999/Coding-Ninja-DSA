#include <iostream>
#include <cmath>

using namespace std;

string combos[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", 
    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void printAllCodes(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }

    printAllCodes(input.substr(1), output + combos[stoi(input.substr(0, 1)) - 1]);
    
    if(input.length() > 1 && stoi(input.substr(0, 2)) <= 26)
        printAllCodes(input.substr(2), output + combos[stoi(input.substr(0, 2)) - 1]);
}

int main(void)
{
    string input, output = "";
    cin>>input;

    printAllCodes(input, output);
}