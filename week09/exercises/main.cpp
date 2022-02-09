#include"complex.h"
int main()  
{
    Complex a(1.1,-2);
    Complex b(1,2.2);
    Complex c;
    c.display();
    c = a.add(b);
    c.display();
    c = a.sub(b);
    c.display();
    c = a.mul(b);
    c.display();
}