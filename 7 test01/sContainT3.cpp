#include <iostream>

using namespace std;

bool sContainT(string s, string t)
{
    if(t.empty())
        return true;
    
    int n = s.find(t[0]);
    if(n < s.length() - t.length() + 1)
        return sContainT(s.substr(n), t.substr(1));

    else
        return false;
}

int main(void)
{
    string s, t;
    cin>>s>>t;

    sContainT(s, t) ? cout<<"True" : cout<<"False";
}