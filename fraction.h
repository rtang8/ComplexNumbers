#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int m_num;
    int m_den;


public:
    Fraction();
    Fraction(int num, int den);
    Fraction(double num);
    ~Fraction();

    void set(int num, int den);
    void print();
    void simplify();
    Fraction simplify(Fraction x);
    Fraction toFrac(double input);
    Fraction sqrt(Fraction x);
    int gcd(long long p, long long q);

    int num() const;
    int den() const;

    // Assignment Operators
    Fraction &operator=(const Fraction &fraction);

    Fraction &operator+=(const Fraction &x);
    Fraction &operator-=(const Fraction &x);
    Fraction &operator*=(const Fraction &x);
    Fraction &operator/=(const Fraction &x);
    Fraction &operator+=(const int &x);
    Fraction &operator-=(const int &x);
    Fraction &operator*=(const int &x);
    Fraction &operator/=(const int &x);

    // Increment Operators
    Fraction &operator++();
    Fraction &operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    // Friend Operators
    friend
        Fraction operator+(const Fraction &x, const Fraction &y);
    friend
        Fraction operator-(const Fraction &x, const Fraction &y);
    friend
        Fraction operator*(const Fraction &x, const Fraction &y);
    friend
        Fraction operator/(const Fraction &x, const Fraction &y);
    friend
        Fraction operator+(const Fraction &x, const int &y);
    friend
        Fraction operator-(const Fraction &x, const int &y);
    friend
        Fraction operator*(const Fraction &x, const int &y);
    friend
        Fraction operator/(const Fraction &x, const int &y);
    friend
        Fraction operator+(const int &x, const Fraction &y);
    friend
        Fraction operator-(const int &x, const Fraction &y);
    friend
        Fraction operator*(const int &x, const Fraction &y);
    friend
        Fraction operator/(const int &x, const Fraction &y);


    // Friend Comparison Operators
    friend
        bool operator==(const Fraction &x, const Fraction &y);
    friend
        bool operator!=(const Fraction &x, const Fraction &y);
    friend
        bool operator<(const Fraction &x, const Fraction &y);
    friend
        bool operator<=(const Fraction &x, const Fraction &y);
    friend
        bool operator>(const Fraction &x, const Fraction &y);
    friend
        bool operator>=(const Fraction &x, const Fraction &y);

    friend
        bool operator==(const Fraction &x, const int &y);
    friend
        bool operator!=(const Fraction &x, const int &y);
    friend
        bool operator<(const Fraction &x, const int &y);
    friend
        bool operator<=(const Fraction &x, const int &y);
    friend
        bool operator>(const Fraction &x, const int &y);
    friend
        bool operator>=(const Fraction &x, const int &y);

    // Friend Print Operators
    friend
        std::ostream &operator<<(std::ostream& os, const Fraction &frac);
};


#endif // FRACTION_H
