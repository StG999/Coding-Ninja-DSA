#include <iostream>

using namespace std;

bool sContainT(string s, string t)
{
    if(t.length() == 0)
        return true;
    
    bool ans = sContainT(s, t.substr(1));

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == t[0])
            return ans;
        
        // else if(s[i] == t[1])
        //     return false;
    }

    return false;
}

int main(void)
{
    string s, t;
    cin>>s;
    cin>>t;

    sContainT(s, t) ? cout<<"True" : cout<<"False";
}