#include <iostream>
#include <stack>

using namespace std;

bool redundantParantheses(string input);

int main()
{
    string s;
    getline(cin, s);

    redundantParantheses(s) ? cout<<"True." : cout<<"False.";
}

bool redundantParantheses(string input)
{
    int i=0, count=0;
    stack <char> stack;

    while(input[i] != 0)
    {
        while(input[i] != 0 && input[i] != ')')
        {
            stack.push(input[i]);
            i++;
        }

        while(!stack.empty() && stack.top() != '(')
        {
            count++;
            stack.pop(); 
        }

        if(count <= 1)
            return true;
        
        if(!stack.empty())
            stack.pop();
            
        count = 0;
        i++;
    }

    return false;
}