/*! \file RationalNumberSimple.cpp
 *
 *  Implements arithmetic for rational numbers 
 *  represented by integral variables.
 *
 *  \author Ulrich Eisenecker
 *  \date December 4, 2023
 */

#include <cmath> // Because of abs().
#include <cstdint> // Because of intmax_t.
#include <iostream>
#include <numeric> // Because of gcd().

using namespace std;

/*! Returns -1 if n < 0, 0 if n == 0, +1 if n > 0.
 */
[[nodiscard]] intmax_t sign(const intmax_t& n);

/*! Normalizes rational number a,b, 
 *  i.e., canonical form and b > 0.
 */
void normalize(intmax_t& a,intmax_t& b);

/*! Inputs rational number a,b from cin.
 */
void inputRationalNumber(intmax_t& a, intmax_t& b);

/*! Outputs rational number a,b to cout.
 */
void outputRationalNumber(const intmax_t& a,
                          const intmax_t& b);

/*! Adds rational numbers a,b and c,d, 
 *  and puts the result in e,f.
 */
void add(const intmax_t& a,const intmax_t& b,
         const intmax_t& c,const intmax_t& d,
         intmax_t& e, intmax_t& f);

/*! Subtracts rational number c,d from a,b, 
 *  and puts the result in e,f.
 */
void subtract(const intmax_t& a,const intmax_t& b,
              const intmax_t& c,const intmax_t& d,
              intmax_t& e, intmax_t& f);

/*! Multiplies rational numbers a,b and c,d, 
 *  and puts the result in e,f.
 */
void multiply(const intmax_t& a,const intmax_t& b,
              const intmax_t& c,const intmax_t& d,
              intmax_t& e, intmax_t& f);

/*! Divides rational number a,b by c,d, 
 *  and puts the result in e,f.
 */
void divide(const intmax_t& a,const intmax_t& b,
            const intmax_t& c,const intmax_t& d,
            intmax_t& e, intmax_t& f);

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
   normalize(m,n);
   cout << "Canonical form = ";
   outputRationalNumber(m,n);
   
   cout << "\n\nRational number arithmetics ..." 
        << endl;;
   intmax_t a { }, b { }, c { }, d { }, e { }, f { };
   cout << "Enter 1st rational number\n";
   inputRationalNumber(a,b);
   cout << "\nEnter 2nd rational number\n";
   inputRationalNumber(c,d);
   add(a,b,c,d,e,f);
   cout << "sum = ";
   outputRationalNumber(e,f);
   cout << endl;
   subtract(a,b,c,d,e,f);   
   cout << "difference = ";
   outputRationalNumber(e,f);
   cout << endl;
   multiply(a,b,c,d,e,f);
   cout << "product = ";
   outputRationalNumber(e,f);
   cout << endl;
   divide(a,b,c,d,e,f);
   cout << "quotient = ";
   outputRationalNumber(e,f);
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

void normalize(intmax_t& a,intmax_t& b)
{
   intmax_t divisor { gcd(a,b) };
   a = sign(a) * sign(b) * abs(a) / divisor;
   b = abs(b) / divisor;
}

void inputRationalNumber(intmax_t& a, intmax_t& b)
{
   cout << "numerator: " << flush;
   cin >> a;
   do
   {
      cout << "denominator: " << flush;
      cin >> b;
      if (b == 0)
      {
         cerr << "Error, denominator may not be 0!" 
              << endl;
      }
   } while (b == 0);
}

void outputRationalNumber(const intmax_t& a,
                          const intmax_t& b)
{
   cout << '('
        << a
        << '/'
        << b
        << ')'
        << flush;
}

void add(const intmax_t& a,const intmax_t& b,
         const intmax_t& c,const intmax_t& d,
         intmax_t& e, intmax_t& f)
{
   e = a * d + b * c;
   f = b * d;
   normalize(e,f);
}

void subtract(const intmax_t& a,const intmax_t& b,
              const intmax_t& c,const intmax_t& d,
              intmax_t& e, intmax_t& f)
{
   e = a * d - b * c;
   f = b * d;
   normalize(e,f);
}

void multiply(const intmax_t& a,const intmax_t& b,
              const intmax_t& c,const intmax_t& d,
              intmax_t& e, intmax_t& f)
{
   e = a * c;
   f = b * d;
   normalize(e,f);
}

void divide(const intmax_t& a,const intmax_t& b,
            const intmax_t& c,const intmax_t& d,
            intmax_t& e,intmax_t& f)
{
   e = a * d;
   f = b * c;
   normalize(e,f);
}
