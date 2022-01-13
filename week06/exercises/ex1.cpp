#include"ex1.h"
std::tuple<int,int> swapByValue(int a,int b)
{
    return {b,a};
}
void swapByPointer(int* a,int *b)
{
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}
void swapByReference(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}