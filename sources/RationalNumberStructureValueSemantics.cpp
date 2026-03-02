/*! \file RationalNumberStructureValueSemantics.cpp
 *
 *  Implements arithmetic for rational numbers 
 *  represented by a struct
 *  using value semantics.
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

/*! Returns normalized rational number r, 
 *  i.e., canonical form and r.denominator > 1.
 */
[[nodiscard]] RationalNumber normalize(const RationalNumber& r);

/*! Inputs rational number r from cin
 *  and returns it as value.
 */
[[nodiscard]] RationalNumber inputRationalNumber();

/*! Outputs rational number r to cout.
 */
void outputRationalNumber(const RationalNumber& r);

/*! Adds rational numbers a and b, and returns the result as value.
 */
[[nodiscard]] RationalNumber add(const RationalNumber& a,
                                 const RationalNumber& b);

/*! Subtracts rational number b from a, and returns the result as value.
 */
[[nodiscard]] RationalNumber subtract(const RationalNumber& a,
                                      const RationalNumber& b);

/*! Multiplies rational numbers a and b, and returns the result as value.
 */
[[nodiscard]] RationalNumber multiply(const RationalNumber& a,
                                      const RationalNumber& b);

/*! Divides rational number a by b,  and returns the result as value.
 */
[[nodiscard]] RationalNumber divide(const RationalNumber& a,
                                    const RationalNumber& b);

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
   o = normalize(o);
   cout << "Canonical form = ";
   outputRationalNumber(o);
   
   cout << "\n\nRational number arithmetics ..." 
        << endl;;
   cout << "Enter 1st rational number\n";
   RationalNumber a { inputRationalNumber() };
   cout << "Enter 2nd rational number\n";
   RationalNumber b { inputRationalNumber() }; 
   cout << "sum = ";
   outputRationalNumber(add(a,b));
   cout << "\ndifference = ";
   outputRationalNumber(subtract(a,b));   
   cout << "\nproduct = ";   
   outputRationalNumber(multiply(a,b));
   cout << "\nquotient = ";
   outputRationalNumber(divide(a,b));
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

RationalNumber normalize(const RationalNumber& r)
{
   intmax_t divisor { gcd(r.numerator,r.denominator) };
   RationalNumber result { };
   result.numerator = sign(r.numerator) * sign(r.denominator) 
                      * abs(r.numerator) / divisor;
   result.denominator = abs(r.denominator) / divisor;
   return result;
}

RationalNumber inputRationalNumber()
{
   RationalNumber result;
   cout << "numerator: " << flush;
   cin >> result.numerator;
   do
   {
      cout << "denominator: " << flush;
      cin >> result.denominator;
      if (result.denominator == 0)
      {
         cerr << "Error, denominator may not be 0!" 
              << endl;
      }
   } while (result.denominator == 0);
   return normalize(result);
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

RationalNumber add(const RationalNumber& a,const RationalNumber& b)
{
   RationalNumber result;
   result.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
   result.denominator = a.denominator * b.denominator;
   return normalize(result);
}

RationalNumber subtract(const RationalNumber& a,const RationalNumber& b)
{
   RationalNumber result;
   result.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
   result.denominator = a.denominator * b.denominator;
   return normalize(result);
}

RationalNumber multiply(const RationalNumber& a,const RationalNumber& b)
{
   RationalNumber result;
   result.numerator = a.numerator * b.numerator;
   result.denominator = a.denominator *  b.denominator;
   return normalize(result);
}

RationalNumber divide(const RationalNumber& a,const RationalNumber& b)
{
   RationalNumber result;
   result.numerator = a.numerator *  b.denominator;
   result.denominator = a.denominator * b.numerator;
   return normalize(result);
}
