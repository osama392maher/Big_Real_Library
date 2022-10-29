#ifndef BIG_REAL_CLASS_BIGREALCLASS_H
#define BIG_REAL_CLASS_BIGREALCLASS_H

#include <iostream>
#include <string>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal{
private:
    BigDecimalInt wholePart;
    BigDecimalInt fractionalPart;
    char sign = '+';
public:
    //Constructors
    explicit BigReal(double realNumber = 0.0);  // Default constructor
    explicit BigReal (string realNumber);
    explicit BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);     // Copy constructor
    BigReal (BigReal&& other);// Move constructor

    //Assignment operators
    BigReal& operator= (BigReal other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment operator

    //Arithmetic operators
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);

    //Comparison operators
    bool operator<  (BigReal anotherReal);
    bool operator>  (BigReal anotherReal);
    bool operator== (BigReal anotherReal);

    //input/output operators
    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& out, BigReal num);

    //Additional functions
    int size();
    int Sign();
    bool checkValidInput(string input);


};
#endif //BIG_REAL_CLASS_BIGREALCLASS_H