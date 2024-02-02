#include <iostream>
#include <stack>

using namespace std;

bool balancedParantheses(string str);

int main()
{
    string s;
    getline(cin, s);

    balancedParantheses(s) ? cout<<"True" : cout<<"False";
}

bool balancedParantheses(string str)
{
    stack <char> sck;
    int i=0;

    while(str[i] != 0)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            sck.push(str[i]);
            i++;
            continue;
        }

        if(str[i] == ')')
        {
            if(sck.empty() || sck.top() != '(')
                return false;
            
            sck.pop();
            i++;
            continue;
        }

        if(str[i] == ']')
        {
            if(sck.empty() || sck.top() != '[')
                return false;
            
            sck.pop();
            i++;
            continue;
        }

        if(str[i] == '}')
        {
            if(sck.empty() || sck.top() != '{')
                return false;
            
            sck.pop();
            i++;
            continue;
        }
        
        i++;
    }

    return sck.empty();
}