#include<stdio.h>
#include<string.h>
#include<stuinfo.hpp>
void inputstu(stuinfo stu[],int n)
{
    printf("Please input information of %d students:\n",n);
    for(int i=0;i<n;i++)
    {
        printf("Student %d`s name:",i);
        fgets(stu[i].name,20,stdin);
        if (stu[i].name[strlen(stu[i].name)-1] == '\n')
            stu[i].name[strlen(stu[i].name)-1] = '\0';
        printf("Student %d`s score:",i);
        for(int j=0;j<3;j++)
        {
            scanf("%lf",&stu[i].score[j]);
        }
        getchar();
    }
}

void showstu(stuinfo stu[],int n)
{
    printf("The information of %d students you input are:\n",n);
    for(int i=0;i<n;i++)
    {
        printf("Student %d`s name: %s,scores: %lf, %lf, %lf\n",i,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
}

void sortstu(stuinfo stu[],int n)
{
    printf("The descending order of %d students:\n",n);
    for(int i=0;i<n;i++)
    {
        stu[i].ave = 0;
        for(int j=0;j<3;j++)
        {
            stu[i].ave+=stu[i].score[j]/3;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(stu[j].ave>stu[i].ave)
            {
                stuinfo tmp;
                tmp = stu[i];
                stu[i] = stu[j];
                stu[j] = tmp;
            }   
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Student %d`s name: %s,scores: %lf, %lf, %lf,average: %lf\n",i,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
    }
}

void findstu(stuinfo stu[],int n)
{
    char ch[20];
    printf("Please input the name you want to find:");
    fgets(ch,20,stdin);
    if (ch[strlen(ch)-1] == '\n')
        ch[strlen(ch)-1] = '\0';
    for(int i=0;i<n;i++)
    {
        if(strcmp(stu[i].name,ch)==0)
        {
            printf("Student %s is in the list,scores: %lf, %lf, %lf,average: %lf\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
            return;
        }
    }
    printf("Student %s is not in the list\n",ch);
}