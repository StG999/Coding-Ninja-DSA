#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int strToInt(char *s)
{
    if(strlen(s) == 1)
        return *s - '0';

    int ans = strToInt(s + 1);

    return (*s - '0')*pow(10, strlen(s) - 1) + ans;
}

int main(void)
{
    char s[11];
    gets(s);

    // cout<<strlen(s);
    int ans = strToInt(s);

    cout<<"Converted Integer: "<<ans;
}