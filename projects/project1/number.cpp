#include "number.h"
#include <assert.h>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
Number::Number()
{
    sign = true;
    exponent = 0;
}
Number::~Number()
{
}

Number::Number(bool sign_, vector<uint8_t> significand_, long exponent_)
    : sign(sign_)
    , significand(significand_)
    , exponent(exponent_)
{
}

Number::Number(const Number& other)
    : sign(other.sign)
    , significand(other.significand)
    , exponent(other.exponent)
{
}

Number Number::opposite() const
{
    Number result = Number(*this);
    result.sign = !sign;
    return result;
}

Number Number::absolute() const
{
    Number result(*this);
    result.sign = true;
    return result;
}

bool isDigit(const char c)
{
    return c >= '0' && c <= '9';
}

bool Number::fromString(const string input)
{
    int length = input.length();
    if(length == 0) {
        cerr << "input is too short" << endl;
        return false;
    }

    int idx = 0;

    while(idx < length && !isDigit(input[idx])) {
        idx++;
    }

    if(idx == length || idx > 1 || (idx == 1 && input[idx - 1] != '+' && input[idx - 1] != '-')) {
        cerr << "invalid sign" << endl;
        return false;
    }

    if(idx == 0) {
        sign = true;
    } else if(idx == 1) {
        if(input[idx - 1] == '+') {
            sign = true;
        } else if(input[idx - 1] == '-') {
            sign = false;
        }
        exponent++;
    }

    while(idx < length && input[idx] != '.') {
        if(!isDigit(input[idx])) {
            cerr << "invalid integer" << endl;
            return false;
        } else {
            significand.push_back(input[idx] - '0');
        }
        idx++;
    }
    exponent = idx - 1 - exponent;
    idx++;
    while(idx < length) {
        if(!isDigit(input[idx])) {
            cerr << "invalid fraction" << endl;
            return false;
        } else {
            significand.push_back(input[idx] - '0');
        }
        idx++;
    }
    return true;
}

const string Number::toString() const
{
    string result;
    if(sign) {
        result.push_back('+');
    } else {
        result.push_back('-');
    }
    if(exponent >= 0) {
        if(exponent + 1 < significand.size()) {
            for(int i = 0; i <= exponent; i++) {
                result.push_back(significand[i] + '0');
            }

            result.push_back('.');

            for(int i = exponent + 1; i < significand.size(); i++) {
                result.push_back(significand[i] + '0');
            }
        } else {
            for(int i = 0; i < significand.size(); i++) {
                result.push_back(significand[i] + '0');
            }
            for(int i = significand.size(); i < exponent + 1; i++) {
                result.push_back('0');
            }
        }

    } else {
        for(int i = exponent; i < 0; i++) {
            result.push_back('0');
            if(i == exponent) {
                result.push_back('.');
            }
        }
        for(int i = 0; i < significand.size(); i++) {
            result.push_back(significand[i] + '0');
        }
    }
    return result;
}

Number add(const Number& a, const Number& b)
{
    if(!a.sign && b.sign) {
        return sub(b.absolute(), a.absolute());
    } else if(a.sign && !b.sign) {
        return sub(a.absolute(), b.absolute());
    } else if(!a.sign && !b.sign) {
        return add(a.absolute(), b.absolute()).opposite();
    }

    Number a_ = a.standardise();
    Number b_ = b.standardise();
    Number result;
    if(a_.exponent > b_.exponent) {
        result.exponent = a_.exponent;
        for(int i = 0; i < a_.exponent - b_.exponent; i++) {
            b_.significand.insert(b_.significand.begin(), 0);
        }
    } else {
        result.exponent = b_.exponent;
        for(int i = 0; i < b_.exponent - a_.exponent; i++) {
            a_.significand.insert(a_.significand.begin(), 0);
        }
    }
    int maxLen = std::max(a_.significand.size(), b_.significand.size());
    for(int i = a_.significand.size(); i < maxLen; i++) {
        a_.significand.push_back(0);
    }
    for(int i = b_.significand.size(); i < maxLen; i++) {
        b_.significand.push_back(0);
    }

    auto iter1 = a_.significand.end();
    auto iter2 = b_.significand.end();
    uint8_t carry = 0;
    while(iter1 != a_.significand.begin() || iter2 != b_.significand.begin()) {
        uint8_t res = carry;
        if(iter1 != a_.significand.begin()) {
            res += *(iter1 - 1);
            iter1--;
        }
        if(iter2 != b_.significand.begin()) {
            res += *(iter2 - 1);
            iter2--;
        }
        result.significand.insert(result.significand.begin(), res % 10);
        carry = res / 10;
    }
    if(carry == 1) {
        result.significand.insert(result.significand.begin(), 1);
        result.exponent++;
    }
    return result;
}

Number sub(const Number& a, const Number& b)
{
    if(a.sign && !b.sign) {
        return add(a.absolute(), b.absolute());
    } else if(!a.sign && b.sign) {
        return add(a.absolute(), b.absolute()).opposite();
    } else if(!a.sign && !b.sign) {
        if(a.absolute() >= b.absolute()) {
            return sub(a.absolute(), b.absolute()).opposite();
        } else {
            return sub(b.absolute(), a.absolute());
        }
    } else if(a.absolute() < b.absolute()) {
        return sub(b.absolute(), a.absolute()).opposite();
    }

    Number a_ = a.standardise();
    Number b_ = b.standardise();
    Number result;
    if(a_.exponent > b_.exponent) {
        result.exponent = a_.exponent;
        for(int i = 0; i < a_.exponent - b_.exponent; i++) {
            b_.significand.insert(b_.significand.begin(), 0);
        }
    } else {
        result.exponent = b_.exponent;
        for(int i = 0; i < b_.exponent - a_.exponent; i++) {
            a_.significand.insert(a_.significand.begin(), 0);
        }
    }
    int maxLen = std::max(a_.significand.size(), b_.significand.size());
    for(int i = a_.significand.size(); i < maxLen; i++) {
        a_.significand.push_back(0);
    }
    for(int i = b_.significand.size(); i < maxLen; i++) {
        b_.significand.push_back(0);
    }

    auto iter1 = a_.significand.end();
    auto iter2 = b_.significand.end();
    uint8_t carry = 0;
    while(iter1 != a_.significand.begin() || iter2 != b_.significand.begin()) {
        uint8_t res = 0;
        if(iter1 != a_.significand.begin()) {
            res += *(iter1 - 1);
            iter1--;
        }
        if(iter2 != b_.significand.begin()) {
            if(res < *(iter2 - 1) + carry) {
                res = res + 10 - (*(iter2 - 1) + carry);
                carry = 1;
            } else {
                res -= *(iter2 - 1) + carry;
                carry = 0;
            }
            iter2--;
        }
        result.significand.insert(result.significand.begin(), res);
    }
    return result;
}

Number mul(const Number& a, const Number& b)
{
    Number a_ = a.standardise();
    Number b_ = b.standardise();
    Number result = KaratsubaCore(a_, b_).standardise();
    result.exponent =
        result.exponent + (a_.exponent + 1 - a_.significand.size()) + (b_.exponent + 1 - b_.significand.size());
    result.sign = (a.sign == b.sign);
    return result;
}

Number Number::operator+(const Number& other) const
{
    return add(other);
}

Number Number::operator-(const Number& other) const
{
    return sub(other);
}

Number Number::operator*(const Number& other) const
{
    return mul(other);
}

Number Number::add(const Number& other) const
{
    return ::add((*this), other);
}

Number Number::sub(const Number& other) const
{
    return ::sub((*this), other);
}

Number Number::mul(const Number& other) const
{
    return ::mul((*this), other);
}

bool Number::operator==(const Number& other) const
{
    Number a_ = standardise();
    Number b_ = other.standardise();
    if(a_.sign != b_.sign) {
        return false;
    }
    if(a_.exponent != b_.exponent) {
        return false;
    }
    if(a_.significand.size() != b_.significand.size()) {
        return false;
    }
    for(int i = 0; i < a_.significand.size(); i++) {
        if(a_.significand[i] != b_.significand[i]) {
            return false;
        }
    }
    return true;
}

bool Number::operator>(const Number& other) const
{
    Number a_ = standardise();
    Number b_ = other.standardise();
    if(a_.sign > b_.sign) {
        return true;
    } else if(a_.sign < b_.sign) {
        return false;
    }
    if(a_.exponent > b_.exponent) {
        return true;
    } else if(a_.exponent < b_.exponent) {
        return false;
    }

    if(a_.sign == true) {
        for(int i = 0; i < a_.significand.size() && i < b_.significand.size(); i++) {
            if(a_.significand[i] > b_.significand[i]) {
                return true;
            } else if(a_.significand[i] < b_.significand[i]) {
                return false;
            }
        }
        if(a_.significand.size() > b_.significand.size()) {
            return true;
        } else {
            return false;
        }
    } else {
        return b_.absolute() < a_.absolute();
    }
}

bool Number::operator<(const Number& other) const
{
    return !((*this) >= other);
}

bool Number::operator>=(const Number& other) const
{
    return ((*this) > other || (*this) == other);
}

bool Number::operator<=(const Number& other) const
{
    return !((*this) > other);
}

Number Number::standardise() const
{
    Number res;
    if(isZero()) {
        res.significand.push_back(0);
        return res;
    }
    int head = 0;
    int tail = significand.size();
    for(int i = 0; i < significand.size(); i++) {
        if(significand[i] == 0) {
            head++;
        } else {
            break;
        }
    }
    for(int i = significand.size() - 1; i >= head; i--) {
        if(significand[i] == 0) {
            tail--;
        } else {
            break;
        }
    }
    for(int i = head; i < tail; i++) {
        res.significand.push_back(significand[i]);
    }
    res.sign = sign;
    res.exponent = exponent - head;
    return res;
}

bool Number::fromVector(const vector<uint8_t> input)
{
    for(int i = 0; i < input.size(); i++) {
        if(input[i] < 10) {
            significand.push_back(input[i]);
        } else {
            return false;
        }
    }
    exponent = input.size() - 1;
    sign = true;
    return true;
}

vector<uint8_t> Number::toVector() const
{
    standardise();
    return significand;
}

Number KaratsubaCore(const Number& a, const Number& b)
{
    vector<uint8_t> vres;
    vector<uint8_t> va = a.toVector();
    vector<uint8_t> vb = b.toVector();
    Number result;
    if(va.size() == 1) {
        uint8_t carry = 0;
        for(int i = 0; i < vb.size(); i++) {
            int idx = vb.size() - 1 - i;
            uint8_t res = vb[idx] * va[0] + carry;
            vres.insert(vres.begin(), res % 10);
            carry = res / 10;
        }
        vres.insert(vres.begin(), carry);
        result.fromVector(vres);
        return result;
    } else if(vb.size() == 1) {
        uint8_t carry = 0;
        for(int i = 0; i < va.size(); i++) {
            int idx = va.size() - 1 - i;
            uint8_t res = va[idx] * vb[0] + carry;
            vres.insert(vres.begin(), res % 10);
            carry = res / 10;
        }
        vres.insert(vres.begin(), carry);
        result.fromVector(vres);
        return result;
    } else {
        int midSize = std::min(va.size(), vb.size()) / 2;
        vector<uint8_t> va1(va.begin(), va.end() - midSize);
        vector<uint8_t> va2(va.end() - midSize, va.end());
        vector<uint8_t> vb1(vb.begin(), vb.end() - midSize);
        vector<uint8_t> vb2(vb.end() - midSize, vb.end());

        Number a1, a2, b1, b2;
        a1.fromVector(va1);
        a2.fromVector(va2);
        b1.fromVector(vb1);
        b2.fromVector(vb2);

        Number x = KaratsubaCore(a1, b1);
        Number y = KaratsubaCore(a2, b2);
        Number z = KaratsubaCore(a1 + a2, b1 + b2) - x - y;
        x.exponent += midSize * 2;
        z.exponent += midSize;
        result = x + y + z;
        return result;
    }
}