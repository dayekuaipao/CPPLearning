#include<iostream>
using namespace std;
int main()
{
    int* a = new int[5]{1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        cout<<*(a+4-i)<<endl;
    }
    delete[] a;
}