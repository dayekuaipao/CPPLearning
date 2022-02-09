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
Complex& Complex::operator=(const Complex& other)
{
    real=other.real;
    imaginary=other.imaginary;
    return (*this);
}
bool Complex::operator==(const Complex&other) const
{
    if(real==other.real&&imaginary==other.imaginary)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os,const Complex& complex)
{
    if(complex.imaginary>=0)
        os<<complex.real<<"+"<<complex.imaginary<<"i";
    else
        os<<complex.real<<complex.imaginary<<"i";
    return os;
}

std::istream& operator>>(std::istream& is,Complex& complex)
{
    is>>complex.real>>complex.imaginary;
    return is;
}