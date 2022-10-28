
void BigReal::BigReal(string realNumber) {
    string wholePart = "";
    string fractionalPart = "";
    int i = 0;
    if (realNumber[0] == '-') {
        sign = '-';
        i++;
    } else {
        sign = '+';
    }
    while (realNumber[i] != '.') {
        wholePart += realNumber[i];
        i++;
    }
    i++;
    while (i < realNumber.length()) {
        fractionalPart += realNumber[i];
        i++;
    }
    this->wholePart = BigDecimalInt(wholePart);
    this->fractionalPart = BigDecimalInt(fractionalPart);
}

BigReal::BigReal(BigDecimalInt bigInteger) {
    this->wholePart = bigInteger;
    this->fractionalPart = BigDecimalInt("0");
    this->sign = bigInteger.sign;
}

