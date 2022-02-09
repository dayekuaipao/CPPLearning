#include"complex.h"
using std::cin,std::cout,std::endl;
int main()  
{
    Complex a(1.1,-2);
    Complex b(1,2.2);
    Complex c;
    cout<<c<<endl;
    c = a+b;
    cout<<c<<endl;
    c = a-b;
    cout<<c<<endl;
    cin>>a>>b;
    c = a*b;
    cout<<c<<endl;
}