#include <iostream>
#include <string.h>

using namespace std;

void removeX(char *s)
{
    if(strlen(s) == 1 && (*s == 'x' || *s == 'X'))
    {   
        *s = '\0';
        return;
    }
    
    else if(strlen(s) == 1 && (*s != 'x' && *s != 'X'))
        return;

    removeX(s+1);

    if(*s == 'x' || *s == 'X')
    {
        char tmp[strlen(s) + 1];
        strcpy(tmp, s);

        for(int i=0; i<strlen(tmp) + 1; i++)
        {
            s[i] = tmp[i + 1];
        }

        return;
    }

    else
        return;
}

int main(void)
{
    char s[1000];
    gets(s);

    removeX(s);

    printf("%s\n", s);
}