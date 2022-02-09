#include <iostream>
class Complex
{
    private:
        double real;
        double imaginary;
    public:
        Complex(double _real=0,double _imaginary=0):real(_real),imaginary(_imaginary){};
        Complex(const Complex& other):real(other.real),imaginary(other.imaginary){};
        double getReal() const{return real;};
        double getImaginary() const{return imaginary;};
        void setReal(double _real){real=_real;};
        void setImaginary(double _imaginary){imaginary=_imaginary;};
        Complex add(const Complex& other) const;
        Complex sub(const Complex& other) const;
        Complex mul(const Complex& other) const;
        Complex operator+(const Complex& other) const{return this->add(other);};
        Complex operator-(const Complex& other) const{return this->sub(other);};
        Complex operator*(const Complex& other) const{return this->mul(other);};
        Complex& operator=(const Complex& other);
        bool operator==(const Complex&other) const;
        bool operator!=(const Complex&other) const{return !((*this)==other);};

        friend std::ostream& operator<<(std::ostream& os,const Complex& complex);
        friend std::istream& operator>>(std::istream& is,Complex& complex);
};