#include "fraction.h"
#include <iostream>
#include <cmath>

/// CONSTRUCTORS
Fraction::Fraction() { m_num = 0; m_den = 1; }
Fraction::Fraction(int num, int den) : m_num(num), m_den(abs(den)) {}

Fraction::~Fraction() {}

/// FUNDAMENTAL FUNCTIONS
void Fraction::set(int num, int den) { m_num = num; m_den = abs(den); }

void Fraction::print() {
    std::cout << m_num << '/' << m_den;
}

void Fraction::simplify() {
    int div = gcd(m_num, m_den);
    m_num /= div;
    m_den /= div;
}

Fraction Fraction::simplify(Fraction x) {
    int div = gcd(x.m_num, x.m_den);
    x.m_num /= div;
    x.m_den /= div;
    return x;
}

/// PRIVATE FUNCTIONS
int Fraction::gcd(int p, int q) {
    return q == 0 ? p : gcd(q, p % q);
}

/// INCREMENT OPERATORS -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
//Prefix
Fraction &Fraction::operator++() {
    Fraction temp(1,1);
    *this = *this + temp;
    return *this;
}

Fraction &Fraction::operator--() {
    Fraction temp(1,1);
    *this = *this - temp;
    return *this;
}

//Postfix
Fraction Fraction::operator++(int) {
    Fraction temp(1,1);
    ++(*this);
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp(1,1);
    --(*this);
    return *this;
}

/// OVERLOAD OPERATORS -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
Fraction &Fraction::operator=(const Fraction &fraction) {
    if(this == &fraction)
        return *this;

    m_num = fraction.m_num;
    m_den = fraction.m_den;
    return *this;
}

Fraction &Fraction::operator+=(const Fraction &x) {
    *this = *this + x;
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &x) {
    *this = *this - x;
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &x) {
    *this = *this * x;
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &x) {
    *this = *this / x;
    return *this;
}

Fraction &Fraction::operator+=(const int &x) {
    Fraction temp(x, 1);
    *this += temp;
    return *this;
}

Fraction &Fraction::operator-=(const int &x) {
    Fraction temp(x, 1);
    *this -= temp;
    return *this;
}

Fraction &Fraction::operator*=(const int &x) {
    Fraction temp(x, 1);
    *this *= temp;
    return *this;
}

Fraction &Fraction::operator/=(const int &x) {
    Fraction temp(x, 1);
    *this /= temp;
    return *this;
}

/// ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~
Fraction operator+(const Fraction &x, const Fraction &y) {
    Fraction temp;
    temp.m_num = x.m_num * y.m_den + x.m_den * y.m_num;
    temp.m_den = x.m_den * y.m_den;
    return temp.simplify(temp);
}

Fraction operator-(const Fraction &x, const Fraction &y) {
    Fraction temp;
    temp.m_num = x.m_num * y.m_den - x.m_den * y.m_num;
    temp.m_den = x.m_den * y.m_den;
    return temp.simplify(temp);

}

Fraction operator*(const Fraction &x, const Fraction &y) {
    Fraction temp;
    temp.m_num = x.m_num * y.m_num;
    temp.m_den = x.m_den * y.m_den;
    return temp.simplify(temp);
}

Fraction operator/(const Fraction &x, const Fraction &y) {
    Fraction temp;
    temp.m_den = x.m_den * y.m_num;
    temp.m_num = x.m_num * y.m_den;
    return temp.simplify(temp);
}

Fraction operator+(const Fraction &x, const int &y) {
    Fraction temp(y, 1);
    return temp.simplify(x + temp);
}

Fraction operator-(const Fraction &x, const int &y) {
    Fraction temp(y, 1);
    return temp.simplify(x - temp);
}

Fraction operator*(const Fraction &x, const int &y) {
    Fraction temp(y, 1);
    return temp.simplify(x * temp);
}

Fraction operator/(const Fraction &x, const int &y) {
    Fraction temp(y, 1);
    return temp.simplify(x / temp);
}

Fraction operator+(const int &x, const Fraction &y) {
    Fraction temp(x, 1);
    return temp.simplify(y + temp);
}

Fraction operator-(const int &x, const Fraction &y) {
    Fraction temp(x, 1);
    return temp.simplify(y - temp);
}

Fraction operator*(const int &x, const Fraction &y) {
    Fraction temp(x, 1);
    return temp.simplify(y * temp);
}

Fraction operator/(const int &x, const Fraction &y) {
    Fraction temp(x, 1);
    return temp.simplify(y / temp);
}



/// Comparison Operators
bool operator==(const Fraction &x, const Fraction &y) {
    Fraction frac1 = x;
    frac1.simplify();
    Fraction frac2 = y;
    frac2.simplify();
    return frac1.m_num == frac2.m_num && frac1.m_den == frac2.m_den;

}

bool operator!=(const Fraction &x, const Fraction &y) {
    return !(x == y);
}

bool operator<(const Fraction &x, const Fraction &y) {
    return x.m_num * y.m_den < y.m_num * x.m_den;
}

bool operator<=(const Fraction &x, const Fraction &y) {
    return x.m_num * y.m_den <= y.m_num * x.m_den;
}

bool operator>(const Fraction &x, const Fraction &y) {
    return x.m_num * y.m_den > y.m_num * x.m_den;
}

bool operator>=(const Fraction &x, const Fraction &y) {
    return x.m_num * y.m_den >= y.m_num * x.m_den;
}








