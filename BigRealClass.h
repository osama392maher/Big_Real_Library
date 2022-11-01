/*  FCAI - Object Oriented Programming - 2022 - Assignment 2
    Program Name: BigRealClass
    Last Modification Date: 01/11/2022
    Author1 and ID and Group: Osama Maher  - 20210060 - B
    Author2 and ID and Group: Maya Ayman   - 20210508 - B
    Author3 and ID and Group: Rawan Younis - 20210524 - B
    Purpose: A C++ class that can hold a real number
    with unlimited number of digits and the supporting
    arithmatic functions.
*/
// #ifndef BIG_REAL_CLASS_BIGREALCLASS_H
// #define BIG_REAL_CLASS_BIGREALCLASS_H

#include <iostream>

#include <string>

#include "BigDecimalIntClass.h"

using namespace std;

class BigReal {
private:
    BigDecimalInt wholePart;
    BigDecimalInt fractionalPart;
    char sign = '+';
public:
    //Constructors
    explicit BigReal(double realNumber = 0.0); // Default constructor
    explicit BigReal(string realNumber);
    explicit BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal & other); // Copy constructor
    BigReal(BigReal && other) noexcept; // Move constructor

    //Assignment operators
    BigReal & operator = (BigReal& other); // Assignment operator
    BigReal & operator = (BigReal && other) noexcept; // Move assignment operator

    //Arithmetic operators
    BigReal operator + (BigReal & other);
    BigReal operator - (BigReal & other);

    //Comparison operators
    bool operator < (const BigReal & anotherReal);
    bool operator > (const BigReal & anotherReal);
    bool operator == (const BigReal & anotherReal);

    //input/output operators
    friend ostream & operator << (ostream & out, BigReal num);
    friend istream & operator >> (istream & in , BigReal & num);

    //Additional functions
    int size();
    char Sign();
    bool checkValidInput(const string & input);
    void removeTrailingZeroes(string&);

    void removeTrailingZeroes();
};
// #endif //BIG_REAL_CLASS_BIGREALCLASS_H