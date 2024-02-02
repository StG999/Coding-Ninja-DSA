#include <iostream>

int multiRecusion(int a, int b)
{
    if (b == 0)
        return 0;
    else if (b == 1)
        return a;

    return a + multiRecusion(a, b-1);
}

int main(void)
{
    int a = 11, b = 0;

    std::cout<<multiRecusion(a, b);
}