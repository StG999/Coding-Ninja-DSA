#include <iostream>
#include <string.h>

using namespace std;

void removeDuplicates(char *s)
{
    if(strlen(s) == 2 && *s == s[1])
    {
        s[1] = '\0';
    }

    else if(strlen(s) == 2 && *s != s[1])
        return;

    removeDuplicates(s+1);

    if(*s == s[1])
    {
        for(int i = 1; i < strlen(s); i++)
        {
            s[i] = s[i+1];
        }

        return;
    }

    else
        return;

}

int main(void)
{
    char s[1001];
    gets(s);

    removeDuplicates(s);

    printf("%s\n", s);
}