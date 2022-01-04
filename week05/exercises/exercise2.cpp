#include<iostream>
using namespace std;
int main()
{
    char* a = new char[5];
    for(int i=0;i<7;i++)
    {
        a[i]='a'+i;
    }
    a[7]=0;
    cout<<a<<endl;
}