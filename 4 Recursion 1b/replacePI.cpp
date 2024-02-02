#include <iostream>

using namespace std;

void replacePI(string s)
{
    int length = s.length();

    if(length == 2 && s[0] == 'p' && s[1] == 'i')
    {
        s[0] = '3';
        s[1] = '.';
        s.push_back('1');
        s.push_back('4');
        return;
    }
    string tmp = s;
    s.pop_back();
    replacePI(s);

    if(s[length - 2] == 'p' && s[length - 1] == 'i')
    {
        s[length - 2] = '3';
        s[length - 1] = '.';
        s.push_back('1');
        s.push_back('4');
        return;
    }

}

int main(void)
{
    string s;
    getline(cin, s);

    replacePI(s);

    cout<<s;
}