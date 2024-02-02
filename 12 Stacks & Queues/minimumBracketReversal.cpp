#include <iostream>
#include <stack>

using namespace std;

int minimumBracketReversal(string s);

int main()
{
    string s;
    getline(cin, s);

    cout<<minimumBracketReversal(s)<<endl;
}

int minimumBracketReversal(string s)
{
    if(s.length() % 2 != 0)
        return -1;

    int i = 0, count = 0;
    stack <char> stack;

    while(s[i] != 0)
    {
        if(s[i] == '{')
        {
            stack.push('{');
            i++;
        }

        else if(s[i] == '}')
        {
            if(stack.empty() || stack.top() == '}')
            {
                stack.push('}');
                i++;
            }

            else if(stack.top() == '{')
            {
                stack.pop();
                i++;
            }
        }
    }

    while(!stack.empty())
    {
        char c1 = stack.top();
        stack.pop();
        char c2 = stack.top();
        stack.pop();

        if(c1 == c2)
            count++;
        
        else
            count += 2;
    }

    return count;
}