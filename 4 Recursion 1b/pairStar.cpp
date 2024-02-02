#include <iostream>
#include <string.h>

using namespace std;

void pairStar(char *s)
{
    if(strlen(s) == 2 && s[0] == s[1])
    {
        s[2] = s[1];
        s[1] = '*';
        s[3] = '\0';
        return;
    }

    else if(strlen(s) == 2 && s[0] != s[1])
        return;
    
    pairStar(s+1);

    if(*s == s[1])
    {
        char tmp[strlen(s) + 1];
        strcpy(tmp, s);

        for(int i=1; i<strlen(s) + 1; i++)
        {
            s[i+1] = tmp[i];
        }

        s[1] = '*';
        return;
    }

    else
        return;
}

int main(void)
{
    char s[1001];
    gets(s);

    pairStar(s);

    printf("%s\n", s);
}