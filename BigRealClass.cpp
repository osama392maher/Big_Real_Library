/*  FCAI - Object-Oriented Programming - 2022 - Assignment 2
    Program Name: BigRealClass
    Last Modification Date: 01/11/2022
    Author1 and ID and Group: Osama Maher  - 20210060 - B
    Author2 and ID and Group: Maya Ayman   - 20210508 - B
    Author3 and ID and Group: Rawan Younis - 20210524 - B
    Purpose: A C++ class that can hold a real number
    with unlimited number of digits and the supporting
    arithmatic functions.
*/
#include "BigRealClass.h"

//___________________________________________
// Constructors
BigReal::BigReal(double realNumber) {
    string num = to_string(realNumber);
    removeTrailingZeroes(num);
    BigReal number(num);
    this -> wholePart = number.wholePart;
    this -> fractionalPart = number.fractionalPart;
    if (!isdigit(num[0])) {
        if (num[0] == '+')
            sign = '+';
        else
            sign = '-';
    }
}

BigReal::BigReal(string realNumbers) {
    if (!checkValidInput(realNumbers)) {
        cout << "Invalid Input" << endl;
        exit(1);
    }
    removeTrailingZeroes(realNumbers);
    string wholeParts = "";
    string fractionalParts = "";
    int i = 0;
    if (realNumbers[0] == '-') {
        sign = '-';
        wholeParts += sign;
        realNumbers.erase(0, 1);
        i++;
    } else {
        wholeParts += sign;
        sign = '+';
    }
    for (i = 0; i < realNumbers.length(); i++) {
        if (realNumbers[i] == '.') {
            for (int j = i + 1; j < realNumbers.length(); j++) {
                fractionalParts += realNumbers[j];
            }
            break;
        }
        wholeParts += realNumbers[i];
    }
    if (wholeParts == "") {
        wholeParts = "0";
    }
    if (fractionalParts == "") {
        fractionalParts = "0";
    }
    wholePart = BigDecimalInt(wholeParts);

    fractionalPart = BigDecimalInt(fractionalParts);
}

BigReal::BigReal(BigDecimalInt bigInteger) {
    this -> wholePart = bigInteger;
    this -> fractionalPart = BigDecimalInt("0");
    if (bigInteger.sign())
        this -> sign = '+';
    else
        this -> sign = '-';
}

BigReal::BigReal(const BigReal & bigReal) {
    this -> wholePart = bigReal.wholePart;
    this -> fractionalPart = bigReal.fractionalPart;
    this -> sign = bigReal.sign;
}
BigReal::BigReal(BigReal && other) noexcept: wholePart(other.wholePart), fractionalPart(other.fractionalPart), sign(other.sign) {}

//___________________________________________
// ِAssignment operators
BigReal & BigReal::operator = (BigReal && other) noexcept {
    if (this != & other) {
        wholePart = other.wholePart;
        fractionalPart = other.fractionalPart;
        sign = other.sign;
    }
    return *this;
}

BigReal & BigReal::operator = (BigReal& other) {
    this -> sign = other.sign;
    this -> wholePart = other.wholePart;
    this -> fractionalPart = other.fractionalPart;
    return ( * this);
}

//___________________________________________
// Arithmetic operators
BigReal BigReal::operator+ (BigReal & other) {
    // ADD NEGATIVE NUMBERS
    if (this -> sign == '-' && other.sign == '-') {
        BigReal a = * this;
        BigReal b = other;
        a.sign = '+';
        b.sign = '+';
        BigReal c = a + b;
        c.sign = '-';
        return c;
    }
    // add positive number to negative number
    if (this -> sign == '+' && other.sign == '-') {
        BigReal a = * this;
        BigReal b = other;
        b.sign = '+';
        return a - b;
    }
    // add negative number to positive number
    if (this -> sign == '-' && other.sign == '+') {
        BigReal a = * this;
        BigReal b = other;
        a.sign = '+';
        return b - a;
    }
    BigReal result;
    string decLHStmp = this->fractionalPart.getNumber(), decRHStmp = other.fractionalPart.getNumber();

    //Padding fraction part with zeroes
    while (decLHStmp.size() < decRHStmp.size()) {
        decLHStmp.push_back('0');
    }
    BigDecimalInt decLHS(decLHStmp);
    while (decLHStmp.size() > decRHStmp.size()) {
        decRHStmp.push_back('0');
    }
    // check signs
    BigDecimalInt decRHS(decRHStmp);
    result.fractionalPart = decLHS + decRHS;

    //Checking if there is a carry from the addition of the fraction part
    if (result.fractionalPart.size() > decLHS.size()) {
        string digit(1, result.fractionalPart.getNumber()[0]);
        BigDecimalInt carry(digit);
        result.wholePart = result.wholePart + carry;
        string newDecPart = result.fractionalPart.getNumber();

        //Removing the carry from the fraction part
        reverse(newDecPart.rbegin(), newDecPart.rend());
        newDecPart.pop_back();
        reverse(newDecPart.rbegin(), newDecPart.rend());
        BigDecimalInt newDec(newDecPart);
        result.fractionalPart = newDec;
    }
    result.wholePart = result.wholePart + this->wholePart + other.wholePart;
    return result;
}

BigReal BigReal::operator- (BigReal & other) {
    string decLHStmp = this->fractionalPart.getNumber(), decRHStmp = other.fractionalPart.getNumber();

    //Padding fraction part with zeroes
    while (decLHStmp.size() < decRHStmp.size()) {
        decLHStmp.push_back('0');
    }
    BigDecimalInt decLHS(decLHStmp);
    while (decLHStmp.size() > decRHStmp.size()) {
        decRHStmp.push_back('0');
    }
    BigDecimalInt decRHS(decRHStmp);

    //Combining whole and fraction parts then subtracting
    string whole = wholePart.getNumber(), fraction = decLHS.getNumber(), tmpNum = this->sign + whole + fraction; //1st number
    BigDecimalInt newNum1(tmpNum);
    whole = other.wholePart.getNumber(), fraction = decRHS.getNumber(), tmpNum = other.sign + whole + fraction; //2nd number
    BigDecimalInt newNum2(tmpNum);

    BigDecimalInt res_without_dec_point = newNum1 - newNum2;

    string res_with_dec_point;
    if (!res_without_dec_point.sign())
        res_with_dec_point = '-' + res_without_dec_point.getNumber();
    else
        res_with_dec_point = res_without_dec_point.getNumber();

    res_with_dec_point.insert(res_with_dec_point.end() - decLHS.size(), '.');

    BigReal finalResult(res_with_dec_point);
    return finalResult;
}

//___________________________________________
// Comparison operators
bool BigReal::operator < (const BigReal & anotherReal) {
    if (this -> sign != anotherReal.sign) {
        return (this -> sign == '-');
    } else {
        if (this -> sign == '+') {
            if (this -> wholePart == anotherReal.wholePart) {
                return (this -> fractionalPart < anotherReal.fractionalPart);
            } else {
                return (this -> wholePart < anotherReal.wholePart);
            }
        } else {
            if (this -> wholePart == anotherReal.wholePart) {
                return (this -> fractionalPart > anotherReal.fractionalPart);
            } else {
                return (this -> wholePart > anotherReal.wholePart);
            }
        }
    }
}
bool BigReal::operator > (const BigReal & anotherReal) {
    if (this -> sign != anotherReal.sign) {
        return (this -> sign == '+');
    } else {
        if (this -> sign == '+') {
            if (this -> wholePart == anotherReal.wholePart) {
                return (this -> fractionalPart > anotherReal.fractionalPart);
            } else {
                return (this -> wholePart > anotherReal.wholePart);
            }
        } else {
            if (this -> wholePart == anotherReal.wholePart) {
                return (this -> fractionalPart < anotherReal.fractionalPart);
            } else {
                return (this -> wholePart < anotherReal.wholePart);
            }
        }
    }
}

bool BigReal::operator == (const BigReal & anotherReal) {
    return (this -> sign == anotherReal.sign &&
            this -> wholePart == anotherReal.wholePart &&
            this -> fractionalPart == anotherReal.fractionalPart);
}

//___________________________________________
// I/O operators
ostream & operator << (ostream & out, BigReal num) {
//    if (num.Sign() == '-') {
//        out << num.Sign();
//    }
    out << num.wholePart << '.' << num.fractionalPart;
    return out;
}

istream & operator >> (istream & in , BigReal & num) {
    string input; in >> input;
    BigReal result(input);
    num = result;
    return in;
}

//___________________________________________
// Additional functions
int BigReal::size() {
    return (this -> wholePart.size() + this -> fractionalPart.size() + 1);
}

char BigReal::Sign() {
    return (this -> sign);
}

//[+-]?((\d+(\.\d*)?)|(\.\d+))
bool BigReal::checkValidInput(const string & input) {
    regex pattern("[+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))");
    return regex_match(input, pattern);
}

void BigReal::removeTrailingZeroes(string &number) {
    while (number.back() == '0')
        number.pop_back();
}
