#include <stdio.h>
#include "complex.h"
Complex Complex::add(const Complex& other) const
{    
    Complex c;
    c.real = real+other.real;
    c.imaginary = imaginary+other.imaginary;
    return c;
}
Complex Complex::sub(const Complex& other) const
{
    Complex c;
    c.real = real-other.real;
    c.imaginary = imaginary-other.imaginary;
    return c;
}
Complex Complex::mul(const Complex& other) const
{
    Complex c;
    c.real = real*other.real-imaginary*other.imaginary;
    c.imaginary = real*other.imaginary+imaginary*other.real;
    return c;
}
void Complex::display() const
{
    if(imaginary>=0)
        printf("%f+%fi\n",real,imaginary);
    else
        printf("%f-%fi\n",real,-imaginary);
}