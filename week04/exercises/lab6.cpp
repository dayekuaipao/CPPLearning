#include<stdio.h>
int main()
{
    char str[20];
    printf("Enter a string:\n");
    gets(str);//fget(str,20,stdin);
    printf("You entered:");
    puts(str);

    printf("Enter another string:\n");
    gets(str);
    printf("You entered:");
    puts(str);

    return 0;
}