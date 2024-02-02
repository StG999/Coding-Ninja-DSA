#include <iostream>

using namespace std;

bool palindrome(string s)
{
    int length = s.length();
    // cout<<0;
    if(length == 1)
        return true;
        
    if(length == 2 && s[0] == s[1])
        return true;
    
    else if(length == 2 && s[0] != s[1])
        return false;
    
    string tmp;
    for(int i=1; i<length-1; i++)
    {
        tmp.push_back(s[i]);
    }
    bool ans = palindrome(tmp);

    if(s[0] == s[length-1] && ans)
        return true;

    else
        return false;
}

int main(void)
{
    string s;
    getline(cin, s);

    cout<<"Palindrome: ";
    palindrome(s) ? cout<<"Yes" : cout<<"No";
}