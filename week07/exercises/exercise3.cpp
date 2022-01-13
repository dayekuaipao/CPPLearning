#include<iostream>
using std::cout,std::endl;
template <typename T>
T minimum(T a,T b)
{
    return a<b?a:b;
}

int main()
{
    int a=4,b=5;
    float c=4.1,d=5.4;
    char e='a',f='g';
    cout<<minimum<int>(a,b)<<endl;
    cout<<minimum<float>(c,d)<<endl;
    cout<<minimum<char>(e,f)<<endl;
}