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
    explicit BigReal(double realNumber = 0.0) {  // Default constructor  //I added implementation (but don't yet know how to remove it from the header)
        string num = to_string(realNumber);
        BigReal number(num);
        this->wholePart = number.wholePart;
        this->fractionalPart = number.fractionalPart;
    }
    explicit BigReal (string realNumber);
    explicit BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);     // Copy constructor
    BigReal (BigReal&& other);      // Move constructor
    BigReal& operator= (BigReal other); // Assignment operator
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

    //Additional functions
};
#endif //BIG_REAL_CLASS_BIGREALCLASS_H
