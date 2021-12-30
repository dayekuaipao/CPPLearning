#ifndef NUMBER_H
#define NUMBER_H
#include <algorithm>
#include <stdint.h>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Number
{
public:
    Number();
    ~Number();

    Number(bool sign_, vector<uint8_t> significand_, long exponent_);
    Number(const Number& other);

    Number add(const Number& other) const;
    Number sub(const Number& other) const;
    Number mul(const Number& other) const;

    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    Number operator*(const Number& other) const;

    bool operator==(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;

    Number opposite() const;
    Number absolute() const;

    bool fromString(const string input);
    const string toString() const;

    bool fromVector(const vector<uint8_t> input);
    vector<uint8_t> toVector() const;

    Number standardise() const;
    bool isZero() const
    {
        return all_of(significand.begin(), significand.end(), [](auto&& i) { return i == 0; });
    }

private:
    vector<uint8_t> significand;
    long exponent;
    bool sign;

    friend Number add(const Number& a, const Number& b);
    friend Number sub(const Number& a, const Number& b);
    friend Number mul(const Number& a, const Number& b);
    friend Number KaratsubaCore(const Number& a, const Number& b);
};

Number add(const Number& a, const Number& b);
Number sub(const Number& a, const Number& b);
Number mul(const Number& a, const Number& b);

Number KaratsubaCore(const Number& a, const Number& b);
bool isDigit(const char c);

#endif
