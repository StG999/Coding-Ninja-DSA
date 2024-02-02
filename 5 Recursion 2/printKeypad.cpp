#include <iostream>

using namespace std;

string combos[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int input, string output)
{
    if(input == 0)
    {
        cout<<output<<endl;
        return;
    }

    for(int i=0; i<combos[input%10-2].length(); i++)
    {
        printKeypad(input/10, output + combos[input%10-2][i]);
    }
}

int main(void)
{
    int input;
    cin>>input;

    string output;

    printKeypad(input, output);
}