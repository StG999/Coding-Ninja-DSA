#include <iostream>

using namespace std;

bool checkAB(string s)
{
    if(s[0] == 'a' && s.length() == 1)
        return true;
    else if(s[0] != 'a' && s.length() == 1)
        return false;

    bool ans = checkAB(s.substr(1));

    if(s[0] != 'a')
        return false;
    
    if(s[1] == 'a' || s.length() == 1)
        return true;

    else if(s[1] == 'b' && s[2] == 'b')
    {
        if(s[3] == 'a' || s.length() == 3)
            return true;
    }

    return false;
}

int main(void)
{
    string s;
    cin>>s;

    // cout<<checkAB(s);
    checkAB(s) ? cout<<"true" : cout<<"false";
}