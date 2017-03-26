#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int m_num;
    int m_den;
    int gcd(int p, int q);

public:
    Fraction();
    Fraction(int num, int den);
    ~Fraction();

    void set(int num, int den);
    void print();
    void simplify();
    Fraction simplify(Fraction x);

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

};

#endif // FRACTION_H
