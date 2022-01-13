#include<stdio.h>
void displaySquare(int side = 4,char filledCharacter = '*')
{
    for(int i=0;i<side;i++)
    {
        for(int j=0;j<side;j++)
        {
            printf("%c",filledCharacter);
        }
        printf("\n");
    }
}
int main()
{
    displaySquare();
    displaySquare(5,'#');
}