#include <iostream>

using namespace std;

int sContainT(string s, string t)
{
    if(t.length() == 0)
        return 1;
    
    int ans = sContainT(s, t.substr(1));

    for(int i=0; i<ans; i++)
    {
        if(s[i] == t[0])
            return i;
    }

    return ans;
}

int main(void)
{
    string s, t;
    cin>>s;
    cin>>t;

    sContainT(s, t) == -1 ? cout<<sContainT(s, t)<<" False" : cout<<sContainT(s, t)<<" True";
}