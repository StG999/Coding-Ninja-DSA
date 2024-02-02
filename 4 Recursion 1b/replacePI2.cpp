#include <iostream>
#include <string.h>

using namespace std;

void replacePI(char *s)
{
    if(strlen(s) == 2 && s[0] == 'p' && s[1] == 'i')
    {
        // s = (char*) realloc(s, strlen(s) + 2);
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
        s[4] = '\0';
        return;
    }

    else if(strlen(s) == 2 && s[0] != 'p')
        return;

    replacePI(s+1);

    if(s[0] == 'p' && s[1] == 'i')
    {

        // s = (char*) realloc(s, strlen(s) + 2);
        char tmp[strlen(s)+1];
        strcpy(tmp, s);

        for(int i = 2; i<strlen(tmp) + 1; i++)
        {
            s[i+2] = tmp[i];
        }
        
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
        return;
    }

    else
        return;
}

int main(void)
{
    // char *s = (char*) malloc(1000 * sizeof(char));
    char s[1000];
    gets(s);

    // cout<<strlen(s);
    // s = (char*) realloc(s, strlen(s) + 1);


    replacePI(s);
    printf("%s\n", s);
}