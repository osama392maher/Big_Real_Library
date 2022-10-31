#include "BigRealClass.h"
#include "BigDecimalIntClass.h"

int main() {
//    BigReal a("-1");
//    BigReal b("-2");
//    BigReal c = a - b;
//    cout << c << endl;

    //Prints invalid input
//    BigReal a2("-1.22");
//    BigReal b2("1.3");
//    BigReal c2(a2 - b2);
//    cout << c2 << endl;
//    cin >> b2;
//    cout << b2 << endl;

    //Prints invalid
//    BigDecimalInt x("1.2");
//    BigReal a("-1.22"), b(x);
//    BigReal c(a - b);
//    cout << c << endl;

    //Prints 1 although it should print 3.44
    BigReal a1(1.22), b1(-2.22);
    BigReal c1(a1 - b1);
    cout << c1 << endl;

}