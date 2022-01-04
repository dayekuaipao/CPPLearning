#include<stdio.h>
int main()
{
    char str[20];
    printf("Enter a string:\n");
    scanf("%s",str);
    printf("You entered:%s\n",str);

    printf("Enter another string:\n");
    scanf("%s",str);
    printf("You entered:%s\n",str);
    return 0;
}