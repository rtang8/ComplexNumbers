#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "fraction.h"
#include "complex.h"

using namespace std;

Complex quadratic(int a, int b, int c);

//typedef Complex (*fptr)(const Complex &x, const Complex &y);

int main(int argc, char *argv[]) {

    stringstream ss;
    int a,b,c;
    string input;

    cout << "Enter the 'a' value :: ";
    getline(cin, input);
    ss << input;
    ss >> a;
    if(ss.fail()) {
        cout << "ERROR :: Invalid Input." << endl;
        exit(1);
    }

    ss.clear();
    cout << "Enter the 'b' value :: ";
    getline(cin, input);
    ss << input;
    ss >> b;
    if(ss.fail()) {
        cout << "ERROR :: Invalid Input." << endl;
        exit(1);
    }

    ss.clear();
    cout << "Enter the 'c' value :: ";
    getline(cin, input);
    ss << input;
    ss >> c;
    if(ss.fail()) {
        cout << "ERROR :: Invalid Input." << endl;
        exit(1);
    }

    Complex temp = temp.quadratic(a,b,c,true);
    Complex temp2 = temp2.quadratic(a,b,c,false);
    cout << "Value 1 : " << temp << endl;
    cout << "Value 2 : " << temp2 << endl;

    cout << endl << "Result of (3+5i)^7" << endl;
    Complex why(3,1,5,1);
    Complex oh(1,1,2,1);
    cout << endl << why % oh << endl;

    return 0;
}


