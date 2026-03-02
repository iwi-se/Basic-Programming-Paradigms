/*! \file RationalNumberStructureReferenceSemantics.cpp
 *
 *  Implements arithmetic for rational numbers
 *  represented by a struct
 *  using reference semantics.
 *
 *  \author Ulrich Eisenecker
 *  \date February 8, 2022
 */

#include <cmath> // Because of abs().
#include <cstdint> // Because of intmax_t.
#include <iostream>
#include <numeric> // Because of gcd().

using namespace std;

/*! Returns -1 if n < 0, 0 if n == 0, +1 if n > 0.
 */
[[nodiscard]] intmax_t sign(const intmax_t& n);

/*! Represents rational number as struct.
 */
struct RationalNumber
{
   /*! Holds numerator of rational number.
    *  By default, numerator is initialized to 0.
    */
    intmax_t numerator  { 0 },
    /*! Holds denominator of rational number.
     *  By default, denominator is initialized to 1.
     */
             denominator { 1 };
};

/*! Normalizes rational number r, 
 *  i.e., canonical form and r.denominator > 0.
 */
void normalize(RationalNumber& r);

/*! Inputs rational number r from cin.
 */
void inputRationalNumber(RationalNumber& r);

/*! Outputs rational number r to cout.
 */
void outputRationalNumber(const RationalNumber& r);

/*! Adds rational numbers a and b, and puts the result in r.
 */
void add(const RationalNumber& a,const RationalNumber& b,
         RationalNumber& r);

/*! Subtracts rational number b from a, and puts the result in r.
 */
void subtract(const RationalNumber& a,const RationalNumber& b,
              RationalNumber& r);

/*! Multiplies rational numbers a and b, and puts the result in r.
 */
void multiply(const RationalNumber& a,const RationalNumber& b,
              RationalNumber& r);

/*! Divides rational number a by b, and puts the result in r.
 */
void divide(const RationalNumber& a,const RationalNumber& b,
            RationalNumber& r);

/*! Executes each function at least once.
 */
int main()
{
   cout << "Helper functions ..." << endl;
   intmax_t m { }, n { };
   cout << "Enter m: ";
   cin >> m;
   cout << "Enter n: ";
   cin >> n;
   cout << "Sign of " << m << " = " << sign(m) << endl;
   cout << "Sign of " << n << " = " << sign(n) << endl;
   RationalNumber o { m, n };
   normalize(o);
   cout << "Canonical form = ";
   outputRationalNumber(o);
   
   cout << "\n\nRational number arithmetics ..." 
        << endl;;
   RationalNumber a { }, b { }, c { };
   cout << "Enter 1st rational number\n";
   inputRationalNumber(a);
   cout << "\nEnter 2nd rational number\n";
   inputRationalNumber(b);
   add(a,b,c);
   cout << "sum = ";
   outputRationalNumber(c);
   cout << endl;
   subtract(a,b,c);   
   cout << "difference = ";
   outputRationalNumber(c);
   cout << endl;
   multiply(a,b,c);
   cout << "product = ";
   outputRationalNumber(c);
   cout << endl;
   divide(a,b,c);
   cout << "quotient = ";
   outputRationalNumber(c);
   cout << endl;
}

intmax_t sign(const intmax_t& n)
{
   if (n < 0)
   {
      return -1;
   }
   if (n > 0)
   {
      return +1;
   }
   return 0;
}

void normalize(RationalNumber& r)
{
   intmax_t divisor { gcd(r.numerator,r.denominator) };
   r.numerator = sign(r.numerator) * sign(r.denominator) 
                 * abs(r.numerator) / divisor;
   r.denominator = abs(r.denominator) / divisor;
}

void inputRationalNumber(RationalNumber& r)
{
   cout << "numerator: " << flush;
   cin >> r.numerator;
   do
   {
      cout << "denominator: " << flush;
      cin >> r.denominator;
      if (r.denominator == 0)
      {
         cerr << "Error, denominator may not be 0!" 
              << endl;
      }
   } while (r.denominator == 0);
}

void outputRationalNumber(const RationalNumber& r)
{
   cout << '('
        << r.numerator
        << '/'
        << r.denominator
        << ')'
        << flush;
}

void add(const RationalNumber& a,const RationalNumber& b,
         RationalNumber& r)
{
   r.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
   r.denominator = a.denominator * b.denominator;
   normalize(r);
}

void subtract(const RationalNumber& a,const RationalNumber& b,
              RationalNumber& r)
{
   r.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
   r.denominator = a.denominator * b.denominator;
   normalize(r);
}

void multiply(const RationalNumber& a,const RationalNumber& b,
              RationalNumber& r)
{
   r.numerator = a.numerator * b.numerator;
   r.denominator = a.denominator *  b.denominator;
   normalize(r);
}

void divide(const RationalNumber& a,const RationalNumber& b,
              RationalNumber& r)
{
   r.numerator = a.numerator *  b.denominator;
   r.denominator = a.denominator * b.numerator;
   normalize(r);
}
