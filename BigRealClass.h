#ifndef BIG_REAL_CLASS_BIGREALCLASS_H
#define BIG_REAL_CLASS_BIGREALCLASS_H
#endif //BIG_REAL_CLASS_BIGREALCLASS_H

#include <iostream>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal{
private:
    BigDecimalInt wholePart;
    BigDecimalInt fractionalPart;
    char sign;
public:
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);     // Copy constructor
    BigReal (BigReal&& other);      // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment operator
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator<  (BigReal anotherReal);
    bool operator>  (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int size();
    int Sign();
    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& out, BigReal num);
};