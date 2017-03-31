#include "complex.h"
#include "fraction.h"
#include <iostream>
#include <cmath>

/// CONSTRUCTORS

Complex::Complex() {
    m_real.set(0, 1);
    m_imag.set(0, 1);
    isNeg = false;
    isImag = true;
}

Complex::Complex(int num, int den, int num2, int den2) {
    m_real.set(num, den);
    m_imag.set(num2, den2);

    if(num2 < 0) isNeg = true;
    else isNeg = false;

    isImag = true;
}

Complex::Complex(Fraction frac1, Fraction frac2) {
    m_real = frac1;
    m_imag = frac2;

    if(frac2 < 0) isNeg = true;
    else isNeg = false;

    isImag = true;
}

Complex::Complex(Fraction frac1, int num2, int den2) {
    m_real = frac1;
    m_imag.set(num2, den2);
    if(num2 < 0) isNeg = true;
    else isNeg = false;

    isImag = true;
}

Complex::~Complex() {}

void Complex::update() {
    isImag = m_imag == 0 ? false : true;
    isNeg = m_imag < 0 ? true : false;
}

void Complex::simplify() {
    if(m_imag.num() != 0) {
        m_imag.simplify();
    }
    m_real.simplify();
}


/// ESSENTIALS

void Complex::set(int a, int b, int c, int d) {
    m_real.set(a,b);
    m_imag.set(c,d);
}

Fraction Complex::real() const{
    return m_real;
}
Fraction Complex::imag() const{
    return m_imag;
}

void Complex::print() {
    m_real.print();
    if(!isNeg && isImag) std::cout << "+";

    if(isImag) {
        m_imag.print();
        std::cout << "i";
    }
}

Complex Complex::addToImag(Fraction x) {
    m_imag += x;
    return *this;
}

Complex Complex::addToImag(int x) {
    Fraction temp(x,1);
    m_imag += temp;
    return *this;
}

Complex Complex::quadratic(int a, int b, int c, bool sign) {
    Complex temp;
    int discrim = (b*b)-(4*a*c);
    if(discrim < 0) {
        double imagPart = sqrt(abs(discrim))/(2 * a);
        Fraction real(-b, 2*a);
        if(sign) {
            Fraction imagine(imagPart);
            Complex asdf(real, imagine);
            temp = asdf;
        }
        else {
            Fraction imagine(imagPart * -1);
            Complex asdf(real, imagine);
            temp = asdf;
        }
    }
    else {
        if(sign)
            temp.set((-1 * b + sqrt(discrim)), (2*a),0,0);
        else
            temp.set((-1 * b - sqrt(discrim)), (2*a),0,0);

    }
    temp.update();
    temp.simplify();

    return temp;
}


/// ASSIGNMENT OPERATOR
Complex &Complex::operator=(const Complex &x) {
    if(this == &x)
        return *this;

    m_real = x.m_real;
    m_imag = x.m_imag;
    return *this;
}

Complex &Complex::operator+=(const Complex &x) {
    *this = *this + x;
    return *this;
}

Complex &Complex::operator-=(const Complex &x) {
    *this = *this - x;
    return *this;
}

Complex &Complex::operator*=(const Complex &x) {
    *this = *this * x;
    return *this;
}

Complex &Complex::operator/=(const Complex &x) {
    *this = *this / x;
    return *this;
}

Complex &Complex::operator+=(const Fraction &x) {
    Complex temp(x,0,1);
    *this = *this + temp;
    return *this;
}

Complex &Complex::operator-=(const Fraction &x) {
    Complex temp(x,0,1);
    *this = *this - temp;
    return *this;
}

Complex &Complex::operator*=(const Fraction &x) {
    Complex temp(x,0,1);
    *this = *this - temp;
    return *this;
}

Complex &Complex::operator/=(const Fraction &x) {
    Complex temp(x,0,1);
    *this = *this - temp;
    return *this;
}

Complex &Complex::operator+=(const int &x) {
    Complex temp(x,1,0,1);
    *this = *this + temp;
    return *this;
}

Complex &Complex::operator-=(const int &x) {
    Complex temp(x,1,0,1);
    *this = *this - temp;
    return *this;
}

Complex &Complex::operator*=(const int &x) {
    Complex temp(x,1,0,1);
    *this = *this * temp;
    return *this;
}

Complex &Complex::operator/=(const int &x) {
    Complex temp(x,1,0,1);
    *this = *this / temp;
    return *this;
}

/// INCREMENT OPERATORS
//Prefix
Complex &Complex::operator++() {
    Complex temp(1,1,0,1);
    *this = *this + temp;
    return *this;
}

Complex &Complex::operator--() {
    Complex temp(1,1,0,1);
    *this = *this - temp;
    return *this;
}

//Postfix
Complex Complex::operator++(int) {
    Complex temp(1,1,0,1);
    ++(*this);
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(1,1,0,1);
    --(*this);
    return *this;
}


/// FRIENDS

std::ostream &operator<<(std::ostream& os, const Complex &x) {
    os << x.m_real;
    if(!x.isNeg && x.isImag) os << "+";

    if(x.isImag) {
        os << x.m_imag;
        os << "i";
    }
    return os;
}

Complex operator+(const Complex &x, const Complex &y) {
    Fraction temp1, temp2;
    temp1 = x.m_real + y.m_real;
    temp2 = x.m_imag + y.m_imag;
    Complex temp(temp1, temp2);
    temp.update();
    return temp;
}

Complex operator-(const Complex &x, const Complex &y) {
    Fraction temp1, temp2;
    temp1 = x.m_real - y.m_real;
    temp2 = x.m_imag - y.m_imag;
    Complex temp(temp1, temp2);
    temp.update();
    return temp;
}

Complex operator*(const Complex &x, const Complex &y) {
    Fraction temp1, temp2;
    temp1 = x.m_real * y.m_real;
    temp2 = x.m_real * y.m_imag + x.m_imag * y.m_real;
    temp1 += x.m_imag * y.m_imag * -1;
    Complex temp(temp1, temp2);
    temp.update();
    return temp;
}

Complex operator/(const Complex &x, const Complex &y) {
    Complex temp1, temp2;
    Complex conjugate;
    conjugate = y;
    conjugate.m_imag *= -1;
    temp1 = x * conjugate;
    temp2 = y * conjugate;

    Complex finalTemp((temp1.m_real/temp2.m_real), (temp1.m_imag/temp2.m_real));
    finalTemp.update();
    return finalTemp;
}

Complex operator+(const Complex &x, const Fraction &y) {
    Complex temp(y, 0, 1);
    return x + temp;
}

Complex operator-(const Complex &x, const Fraction &y) {
    Complex temp(y, 0, 1);
    return x - temp;
}

Complex operator*(const Complex &x, const Fraction &y) {
    Complex temp(y, 0, 1);
    return x * temp;
}

Complex operator/(const Complex &x, const Fraction &y) {
    Complex temp(y, 0, 1);
    return x / temp;
}

Complex operator+(const Complex &x, const int &y) {
    Complex temp(y,1,0,1);
    return (x + temp);
}

Complex operator-(const Complex &x, const int &y) {
    Complex temp(y,1,0,1);
    return x - temp;
}

Complex operator*(const Complex &x, const int &y) {
    Complex temp(y,1,0,1);
    return x * temp;
}

Complex operator/(const Complex &x, const int &y) {
    Complex temp(y,1,0,1);
    return x / temp;
}


// Oh my god it works
Complex operator%(const Complex &x, const double &y) {
    Fraction xReal = x.real();
    Fraction xImag = x.imag();
    double xRealDouble = xReal.num()/xReal.den();
    double xImagDouble = xImag.num()/xImag.den();
    ///std::cout << xRealDouble << " " << xImagDouble << std::endl;
    double r = sqrt(pow(xRealDouble,2) + pow(xImagDouble, 2));
    ///std::cout << r << std::endl;

    double p = atan(xImagDouble/xRealDouble);
    r = pow(r, y);
    p *= y;

    Fraction upper = cos(p)*r;
    Fraction lower = sin(p)*r;
    Complex temp(upper, lower);
    return temp;
}

Complex operator%(const Complex &x, const Complex &y) {
    Fraction xReal = x.real();
    Fraction xImag = x.imag();
    Fraction yReal = y.real();
    Fraction yImag = y.imag();
    double xRealDouble = xReal.num()/xReal.den();
    double xImagDouble = xImag.num()/xImag.den();

    double c = yReal.num()/yReal.den();
    double d = yImag.num()/yImag.den();
    double r = sqrt(pow(xRealDouble,2) + pow(xImagDouble, 2));
    double p = atan(xImagDouble/xRealDouble);

    double left = pow(r,c) * exp(d * -1 * p);

    Fraction upper = cos(d * log(r) + c * p) * left;
    Fraction lower = sin(d * log(r) + c * p) * left;
    Complex temp(upper, lower);
    return temp;


}

