#include "BigRealClass.h"

BigReal::BigReal(double realNumber) {
    string num = to_string(realNumber);
    BigReal number(num);
    this->wholePart = number.wholePart;
    this->fractionalPart = number.fractionalPart;
}
BigReal::BigReal(string realNumber) {
    if(!checkValidInput(realNumber)){
        cout << "Invalid" << "\n";
        exit(1);
    }
    string wholeParts = "";
    string fractionalParts = "";
    int i = 0;
    if (realNumber[0] == '-') {
        sign = '-';
        i++;
    } else {
        sign = '+';
    }
    while (realNumber[i] != '.') {
        wholeParts += realNumber[i];
        i++;
    }
    i++;
    while (i < realNumber.length()) {
        fractionalParts += realNumber[i];
        i++;
    }
    wholePart = BigDecimalInt(wholeParts);
    fractionalPart = BigDecimalInt(fractionalParts);
}

BigReal::BigReal(BigDecimalInt bigInteger) {
    this->wholePart = bigInteger;
    this->fractionalPart = BigDecimalInt("0");
    this->sign = bigInteger.Sign();
}

BigReal::BigReal(const BigReal& bigReal) {
    this->wholePart = bigReal.wholePart;
    this->fractionalPart = bigReal.fractionalPart;
    this->sign = bigReal.sign;
}


BigReal& BigReal::operator= (BigReal other){
    this->sign = other.sign;
    this->wholePart = other.wholePart;
    this ->fractionalPart = other.fractionalPart;
    return (*this);
}

BigReal BigReal::operator+(BigReal& other) {
    BigReal result;
    BigDecimalInt decLHStmp = this->fractionalPart, decRHStmp = other.fractionalPart;

    //Padding fraction part with zeroes
    while (decLHStmp.size() < decRHStmp.size()) {
        decLHStmp.push_back('0');
    }
    BigDecimalInt decLHS(decLHStmp);
    while (decLHStmp.size() > decRHStmp.size()) {
        decRHStmp.push_back('0');
    }
    BigDecimalInt decRHS(decRHStmp);
    result.fractionalPart = decLHS + decRHS;

    //Checking if there is a carry from the addition of the fraction part
    if (result.fractionalPart.size() > decLHS.size()) {
        string digit(1, result.fractionalPart.getnum()[0]);
        BigDecimalInt carry(digit);
        result.wholePart = result.wholePart + carry;
        string newDecPart = result.fractionalPart.getnum();

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

BigReal BigReal::operator-(BigReal &other) {
    BigDecimalInt decLHStmp = this->fractionalPart, decRHStmp = other.fractionalPart;

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
    string whole = wholePart.getnum(), fraction = decLHStmp.getnum(), tmpNum = whole + fraction; //1st number
    BigDecimalInt newNum1(tmpNum);
    whole = other.wholePart.getnum(), fraction = decRHS.getnum(), tmpNum = whole + fraction; //2nd number
    BigDecimalInt newNum2(tmpNum);

    BigDecimalInt res_without_dec_point = newNum1 - newNum2;
    string res_with_dec_point = res_without_dec_point.getnum();
    res_with_dec_point.insert(res_with_dec_point.end() - decLHS.size(), '.');

    BigReal finalResult(res_with_dec_point);
    return finalResult;
}

bool BigReal::operator<  (const BigReal& anotherReal){
    if (this->sign != anotherReal.sign){
        return (this->sign == '-');
    }else{
        if (this->sign == '+'){
            if (this->wholePart == anotherReal.wholePart){
                return (this->fractionalPart < anotherReal.fractionalPart);
            }else {
                return (this->wholePart < anotherReal.wholePart);
            }
        }else{
            if (this->wholePart == anotherReal.wholePart){
                return (this->fractionalPart > anotherReal.fractionalPart);
            }else {
                return (this->wholePart > anotherReal.wholePart);
            }
        }
    }
}

bool BigReal::operator>  (const BigReal& anotherReal){
    if (this->sign != anotherReal.sign){
        return (this->sign == '+');
    }else{
        if (this->sign == '+'){
            if (this->wholePart == anotherReal.wholePart){
                return (this->fractionalPart > anotherReal.fractionalPart);
            }else {
                return (this->wholePart > anotherReal.wholePart);
            }
        }else{
            if (this->wholePart == anotherReal.wholePart){
                return (this->fractionalPart < anotherReal.fractionalPart);
            }else {
                return (this->wholePart < anotherReal.wholePart);
            }
        }
    }
}

bool BigReal::operator== (const BigReal& anotherReal){
    return (this->sign == anotherReal.sign
    && this->wholePart == anotherReal.wholePart
    && this->fractionalPart == anotherReal.fractionalPart);
}

int BigReal:: size(){
    return (this->wholePart.size() + this->fractionalPart.size() + 1);
}

char BigReal:: Sign(){
    return (this->sign);
}

ostream& operator << (ostream& out,  BigReal num){
    if (num.Sign() == '-'){
        out << num.Sign();
    }
    out << num.wholePart << '.' << num.fractionalPart <<"\n";
    return out;
}

<<<<<<< Updated upstream
istream& operator >> (istream& in, BigReal& num){
    string input;
    in >> input;
    BigReal result(input);
    num = result;
    return in;
}
=======
//istream& operator >> (istream& out, BigReal num)
//{
//    string input;
//    out >> input;
//    BigReal result(input);
//    num = result;
//    return out;
//}
>>>>>>> Stashed changes

//(\d*\.)?\d+
bool BigReal::checkValidInput(string input) {
    regex pattern("((-)?\\d*\\.)?\\d+");
    return regex_match(input, pattern);
}

