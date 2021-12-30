#include "fib.hpp"
#include "stdio.h"
int main()
{
    int n;
    printf("start!\n");
    while (true)
    {
        printf("Please input a positive integer:");
        scanf("%d", &n);
        if (n > 0)
        {
            for (int i = 1; i <= n; i++)
            {
                int res = fib(i);
                printf("%d  ", res);
                if (i % 10 == 0)
                {
                    printf("\n");
                }
            }
        }
        else
        {
            break;
        }
        printf("\n");
    }
}