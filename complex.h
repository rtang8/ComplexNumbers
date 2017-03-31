#ifndef COMPLEX_H
#define COMPLEX_H

#include "fraction.h"
#include <iostream>

class Complex {
private:
    Fraction m_real;
    Fraction m_imag;
    bool isNeg;
    bool isImag;

    void update();

public:

    Complex();
    Complex(int num, int den, int num2, int den2);
    Complex(Fraction frac1, Fraction frac2);
    Complex(Fraction frac1, int num2, int den2);
    ~Complex();

    void print();
    void set(int a, int b, int c, int d);
    Fraction real() const;
    Fraction imag() const;
    void simplify();

    Complex addToImag(Fraction x);
    Complex addToImag(int x);
    Complex quadratic(int a, int b, int c, bool sign);


    // Assignment Operators
    Complex &operator=(const Complex &fraction);

    // Increment Operators
    Complex &operator++();
    Complex &operator--();
    Complex operator++(int);
    Complex operator--(int);

    Complex &operator+=(const Complex &x);
    Complex &operator-=(const Complex &x);
    Complex &operator*=(const Complex &x);
    Complex &operator/=(const Complex &x);
    Complex &operator+=(const Fraction &x);
    Complex &operator-=(const Fraction &x);
    Complex &operator*=(const Fraction &x);
    Complex &operator/=(const Fraction &x);
    Complex &operator+=(const int &x);
    Complex &operator-=(const int &x);
    Complex &operator*=(const int &x);
    Complex &operator/=(const int &x);

    // Friend Output Operators
    friend
        std::ostream &operator<<(std::ostream &os, const Complex &x);

    // Friend Operators
    friend
        Complex operator+(const Complex &x, const Complex &y);
    friend
        Complex operator-(const Complex &x, const Complex &y);
    friend
        Complex operator*(const Complex &x, const Complex &y);
    friend
        Complex operator/(const Complex &x, const Complex &y);
    friend
        Complex operator+(const Complex &x, const Fraction &y);
    friend
        Complex operator-(const Complex &x, const Fraction &y);
    friend
        Complex operator*(const Complex &x, const Fraction &y);
    friend
        Complex operator/(const Complex &x, const Fraction &y);
    friend
        Complex operator+(const Complex &x, const int &y);
    friend
        Complex operator-(const Complex &x, const int &y);
    friend
        Complex operator*(const Complex &x, const int &y);
    friend
        Complex operator/(const Complex &x, const int &y);

    friend
        Complex operator%(const Complex &x, const double &y);
    friend
        Complex operator%(const Complex &x, const Complex &y);

};

#endif // COMPLEX_H
