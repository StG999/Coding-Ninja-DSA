#include <iostream>
#include <string.h>

using namespace std;

void charReplace(char *s, char toReplace, char replacedBy)
{
    if(strlen(s) == 1 && *s == toReplace)
    {
        *s = replacedBy;
        return;
    }

    else if(strlen(s) == 1 && *s != toReplace)
    {
        return;
    }

    charReplace(s+1, toReplace, replacedBy);

    if(*s == toReplace)
    {
        *s = replacedBy;
        return;
    }

    else    
        return;
}

int main(void)
{
    char s[1000001];
    gets(s);

    char c1, c2;
    cin>>c1>>c2;

    charReplace(s, c1, c2);

    printf("%s\n", s);
}