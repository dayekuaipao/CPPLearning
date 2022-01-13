#include <stdio.h>
#include <string.h>
char* match(char* s,char ch)
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==ch)
        {
            return &s[i];
        }
    }
    return NULL;
}
int main()
{
    printf("Please input a string:\n");
    char s[40];
    fgets(s,40,stdin);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
    printf("%s\n",s);
    printf("Please input a character:\n");
    char ch;
    scanf("%c",&ch);
    char* res = match(s,ch);
    if(res!=NULL)
        printf("%s\n",res);
    else
        printf("Not found.\n");
}