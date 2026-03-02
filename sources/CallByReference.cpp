// CallByReference by Ulrich Eisenecker, April 6, 2021

#include <iostream>
using namespace std;

void integralDivision(unsigned int & dividend, unsigned int & divisor,
                      unsigned int & quotient, unsigned int & remainder)
{
   cout << "Entering integralDivision() ... \n"
        << "Memory address of dividend = " 
        << (&dividend)
        << endl;
   quotient = dividend / divisor;
   remainder = dividend % divisor;
}

int main()
{
   unsigned int dividend { 99 },
                divisor { 16 },
                quotient { },
                remainder { };
   cout << "In main() ...\n"
        << "Memory address of dividend = "
        << (&dividend)
        << endl;

   integralDivision(dividend,divisor,quotient,remainder);

   cout << "... back in main()\n"
        << dividend 
        << " integrally divided by "
        << divisor
        << " is "
        << quotient
        << ", remainder "
        << remainder
        << '.'
        << endl;
}
