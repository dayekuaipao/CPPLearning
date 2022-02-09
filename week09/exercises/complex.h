class Complex
{
    private:
        double real;
        double imaginary;
    public:
        Complex(double _real=0,double _imaginary=0):real(_real),imaginary(_imaginary){};
        double getReal() const{return real;};
        double getImaginary() const{return imaginary;};
        void setReal(double _real){real=_real;};
        void setImaginary(double _imaginary){imaginary=_imaginary;};
        Complex add(const Complex& other) const;
        Complex sub(const Complex& other) const;
        Complex mul(const Complex& other) const;
        void display() const;
};