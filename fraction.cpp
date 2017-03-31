#include "fraction.h"
#include <iostream>
#include <cmath>

/// CONSTRUCTORS
Fraction::Fraction() { m_num = 0; m_den = 1; }
Fraction::Fraction(int num, int den) : m_num(num), m_den(abs(den)) {}
Fraction::Fraction(double num) {
    Fraction temp = toFrac(num);
    m_num = temp.m_num;
    m_den = temp.m_den;
}

Fraction::~Fraction() {}

/// FUNDAMENTAL FUNCTIONS
void Fraction::set(int num, int den) {
    m_num = num;
    m_den = abs(den);
}

void Fraction::print() {
    std::cout << m_num;
    if(m_den != 1) std::cout << '/' << m_den;
}

void Fraction::simplify() {
    if(m_den != 0) {
        long div = abs(gcd(m_num, m_den));
        m_num /= div;
        m_den /= div;
    }
}

Fraction Fraction::simplify(Fraction x) {
    long div = abs(gcd(x.m_num, x.m_den));
    std::cout << "DIV IS :: " << div << std::endl;
    x.m_num /= div;
    x.m_den /= div;
    return x;
}

Fraction Fraction::toFrac(double x) {
    Fraction temp;
    const long PERCISION = 1000000000;
    double whole = std::floor(x);
    double frac = x-whole;

    long gcd = temp.gcd(round(frac * PERCISION), PERCISION);

    long den = PERCISION / gcd;
    long num = round(frac * PERCISION) / gcd;
    temp.set(num+(den*whole), den);
    return temp;
}

Fraction Fraction::sqrt(Fraction x) {
    double temp = std::sqrt(x.m_num) / std::sqrt(x.m_den);
    Fraction frac = toFrac(temp);
    return frac;
}

int Fraction::num() const {
    return m_num;
}

int Fraction::den() const {
    return m_den;
}

/// PRIVATE FUNCTIONS
int Fraction::gcd(long long p, long long q) {
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



/// COMPARISON OPERATORS
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


bool operator==(const Fraction &x, const int &y) {
    Fraction frac1 = x;
    frac1.simplify();
    Fraction frac2(y, 1);
    return frac1.m_num == frac2.m_num && frac1.m_den == frac2.m_den;
}

bool operator!=(const Fraction &x, const int &y) {
    Fraction frac(y, 1);
    return !(x == frac);
}

bool operator<(const Fraction &x, const int &y) {
    Fraction frac(y, 1);
    return x.m_num * frac.m_den < frac.m_num * x.m_den;
}

bool operator<=(const Fraction &x, const int &y) {
    Fraction frac(y, 1);
    return x.m_num * frac.m_den <= frac.m_num * x.m_den;
}

bool operator>(const Fraction &x, const int &y) {
    Fraction frac(y, 1);
    return x.m_num * frac.m_den > frac.m_num * x.m_den;
}

bool operator>=(const Fraction &x, const int &y) {
    Fraction frac(y, 1);
    return x.m_num * frac.m_den >= frac.m_num * x.m_den;
}

std::ostream &operator<<(std::ostream& os, const Fraction &frac) {
    os << frac.m_num;
    if(frac.m_den != 1) os << '/' << frac.m_den;
    return os;
}








