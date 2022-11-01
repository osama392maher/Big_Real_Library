/*  FCAI - Object-Oriented Programming - 2022 - Assignment 2
    Program Name: BigRealClass
    Last Modification Date: 01/11/2022
    Author1 and ID and Group: Osama Maher  - 20210060 - B
    Author2 and ID and Group: Maya Ayman   - 20210508 - B
    Author3 and ID and Group: Rawan Younis - 20210524 - B
    Purpose: A C++ class that can hold a real number
    with unlimited number of digits and the supporting
    arithmetic functions.
*/
#include "BigRealClass.h"
#include "BigDecimalIntClass.h"

int main() {

    /*************************************************Test One********************************************************/
    BigReal numberOne("75.344444"), numberTwo(25.66), numberThree;
    numberThree = numberOne + numberTwo;

    cout << "Test One : "<< "\n";
    cout << numberOne << " + " << numberTwo << " = " << numberThree << "\n";
    cout << numberOne << " - " << numberTwo << " = " << numberOne - numberTwo << "\n";
    cout << "Is " << numberOne << " < " << numberTwo << " ? " << boolalpha << (numberOne < numberTwo) << "\n";
    cout << "Is " << numberOne << " > " << numberTwo << " ? " << boolalpha << (numberOne > numberTwo) << "\n";
    cout << "Is " << numberOne << " == " << numberTwo << " ? " << boolalpha << (numberOne == numberTwo) << "\n";

    cout << "\n\n";

    /*************************************************Test Two********************************************************/
    numberOne = BigReal("-134.98");
    BigDecimalInt decIntOne("-50");
    numberTwo = BigReal(decIntOne);
    numberThree = numberOne + numberTwo;

    cout << "Test Two : "<< "\n";
    cout << numberOne << " + " << numberTwo << " = " << numberThree << "\n";
    cout << numberOne << " - " << numberTwo << " = " << numberOne - numberTwo << "\n";
    cout << "Is " << numberOne << " < " << numberTwo << " ? " << boolalpha << (numberOne < numberTwo) << "\n";
    cout << "Is " << numberOne << " > " << numberTwo << " ? " << boolalpha << (numberOne > numberTwo) << "\n";
    cout << "Is " << numberOne << " == " << numberTwo << " ? " << boolalpha << (numberOne == numberTwo) << "\n";

    cout << "\n\n";

    /*************************************************Test Three******************************************************/
    numberOne = BigReal("178.90067");
    numberTwo = BigReal("-256.4");
    numberThree = numberOne + numberTwo;

    cout << "Test Three : "<< "\n";
    cout << numberOne << " + " << numberTwo << " = " << numberThree << "\n";
    cout << numberOne << " - " << numberTwo << " = " << numberOne - numberTwo << "\n";
    cout << "Is " << numberOne << " < " << numberTwo << " ? " << boolalpha << (numberOne < numberTwo) << "\n";
    cout << "Is " << numberOne << " > " << numberTwo << " ? " << boolalpha << (numberOne > numberTwo) << "\n";
    cout << "Is " << numberOne << " == " << numberTwo << " ? " << boolalpha << (numberOne == numberTwo) << "\n";
    cout << numberOne << "'s sign is " << numberOne.Sign() << "\n";
    cout << numberTwo << "'s size is " << numberTwo.size() << "\n";

    cout << "\n\n";
}