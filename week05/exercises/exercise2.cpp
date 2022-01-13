#include<iostream>
using namespace std;
int main()
{
    char* b = new char[4]{"abc"};
    char* a = new char[5];
    for(int i=0;i<7;i++)
    {
        a[i]='a'+i;
    }

    cout<<a<<endl;
    cout<<b<<endl;
    delete[] a;
    delete[] b;
}