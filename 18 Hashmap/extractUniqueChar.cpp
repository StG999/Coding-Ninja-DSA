#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void func(string input)
{
    unordered_map <char, bool> map;

    for(int i=0; i<input.length(); i++)
    {
        if(map.count(input[i]))
            continue;
        
        cout<<input[i];
        map[input[i]] = true;
    }
}


int main()
{
    string input = "ababbdcsdabs";
    func(input);
}