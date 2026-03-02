/*! \file main.cpp
 *
 *  Demo application for rational numbers
 *  and corresponding operators
 *
 *  \author Ulrich Eisenecker
 *  \date June 25, 2021 */

#include <iostream>
#include <sstream>
using namespace std;

#include "rational_number.hpp"
#include "rational_number_operators.hpp"
using namespace rational_number;

/*! Calls operators related to RationalNumber.
 */
int main()
{
   cout << "Please enter rational number"
        << endl;
   RationalNumber a { RationalNumber::input() },
                  b { 2,3 },
                  c { 5,7 },
                  d { 11,13 };
   RationalNumber sum { a + b + c + d };
   cout << a << " + " << b << " + "
        << c << " + " << d << " = "
        << sum
        << endl;
   cout << sum << " = "
        << sum.toLongDouble()
        << endl;
   ostringstream oss;
   oss << (a - b) << (b * c) << (c / d);
   RationalNumber difference, product, quotient;
   istringstream iss { oss.str() };
   iss >> difference >> product >> quotient;
   cout << a << " - " << b << " = "
        << difference << endl
        << b << " * " << c << " = "
        << product << endl
        << c << " / " << d << " = "
        << quotient << endl;
}
