#include <iostream>
#include "rational_number.hpp"

using namespace std;

int main()
{
   RationalNumber a { }, b { }, c { };
   cout << "Enter 1st rational number\n";
   a.input();
   cout << "Enter 2nd rational number\n";
   b.input();
   c = a; // Assign a to b to save its state,
   a.add(b);
   cout << "sum = ";
   a.output();
   cout << endl;
   a = c; // Restore saved state of a.
   a.subtract(b);   
   cout << "difference = ";
   a.output();
   cout << endl;
   a = c; // Restore saved state of a.
   a.multiply(b);
   cout << "product = ";
   a.output();
   cout << endl;
   a.numerator(c.numerator()); // Restore saved numerator of a.
   a.denominator(c.denominator()); // Restore saved denominator of a.
   a.divide(b);
   cout << "quotient = ";
   a.output();
   cout << endl;
}
