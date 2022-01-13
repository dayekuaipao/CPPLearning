#include "ex1.h"
#include <iostream>
using std::cout,std::endl;
int main()
{
    int a=2;
    int b=3;
    auto [x,y] = swapByValue(a,b);
    cout<<x<<" "<<y<<endl;
    swapByPointer(&a,&b);
    cout<<a<<" "<<b<<endl;
    swapByReference(a,b);
    cout<<a<<" "<<b<<endl;
}