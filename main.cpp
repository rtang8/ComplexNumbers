#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "fraction.h"

using namespace std;

//typedef Complex (*fptr)(const Complex &x, const Complex &y);

int main(int argc, char *argv[]) {
    Fraction frac1(2, 1);
    Fraction frac2(1, 2);

    frac1 = (frac1 * frac2);
    frac1.print();

    cout << endl << pow(2.0, (.5)) << endl;

    return 0;
}
