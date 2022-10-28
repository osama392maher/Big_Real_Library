#include "BigRealClass.h"


BigReal::BigReal(string realNumber) {
    string wholeParts = "";
    string fractionalParts = "";
    int i = 0;
    if (realNumber[0] == '-') {
        sign = '-';
        i++;
    } else {
        sign= '+';
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



