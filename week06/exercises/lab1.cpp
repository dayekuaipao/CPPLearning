#include <stdio.h>
int *func(int a)
{
    int b = a;
    return &b;
}
int main()
{
    int *b = func(1);
    printf("%d",*b);
}