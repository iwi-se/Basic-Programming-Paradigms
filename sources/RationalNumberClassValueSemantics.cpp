/*! \file RationalNumberClassValueSemantics.cpp
 *
 *  Implements arithmetic for rational numbers
 *  represented by a class
 *  using value semantics.
 *
 *  \author Ulrich Eisenecker
 *  \date March 16, 2025
 */

#include <cmath> // Because of abs().
#include <cstdint> // Because of intmax_t.
#include <iostream>
#include <numeric> // Because of gcd().

using namespace std;

/*! Returns -1 if n < 0, 0 if n == 0, +1 if n > 0.
 */
[[nodiscard]] intmax_t sign(const intmax_t& n);

/*! Represents rational number as  class.
 */
class RationalNumber
{
   public:
      /*! Constructs a normalized RationalNumber exemplar
       * with n for m_numerator and d for d_denominator;
       * default value for n is 0,
       * default value for d is 1.
       */
      RationalNumber(const intmax_t& n = 0, const intmax_t& d = 1):
         m_numerator { n }, m_denominator { d }
      {
         normalize();
      }
      /*! Returns m_numerator as reference to const.
       */
      [[nodiscard]] const intmax_t& numerator() const
      {
         return m_numerator;
      }
      /*! Returns m_denominator as reference to const.
       */
      [[nodiscard]] const intmax_t& denominator() const
      {
         return m_denominator;
      }
      /*! Adds rational numbers *this and r,
       *  and returns result as value.
       */
      [[nodiscard]] RationalNumber add(const RationalNumber& r) const;
      /*! Subtracts rational number r from *this,
       *  and returns result as value.
       */
      [[nodiscard]] RationalNumber subtract(const RationalNumber& r) const;
      /*! Multiplies rational numbers *this and r,
       *  and returns result as value.
       */
      [[nodiscard]] RationalNumber multiply(const RationalNumber& r) const;
      /*! Divides rational numbers *this by r,
       *  and returns result as value.
       */
      [[nodiscard]] RationalNumber divide(const RationalNumber& r) const;
      /*! Outputs rational number to cout.
       */
      void output() const;
   private:
      /*! Normalizes rational number,
       *  i.e., canonical form and m_denominator > 0.
       */
      void normalize();
      /*! Holds numerator of rational number.
       *  By default, numerator is initialized to 0.
       */
      intmax_t  m_numerator { 0 },
      /*! Holds denominator of rational number.
       *  By default, denominator is initialized to 1.
       */
                m_denominator { 1 };
};

/*! Inputs rational number from cin
 *  and returns it as value.
 */
[[nodiscard]] RationalNumber inputRationalNumber();

/*! Executes each free function and
 *  each member function of RationalNumber
 *  at least once.
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

   cout << "\n\nRational number arithmetics ..."
        << endl;
   cout << "Enter 1st rational number\n";
   RationalNumber a { inputRationalNumber() };
   cout << "Numerator (a) = " << a.numerator()
        << "\nDenominator (a) = " << a.denominator()
        << endl;
   cout << "Enter 2nd rational number\n";
   RationalNumber b { inputRationalNumber() };
   cout << "sum = ";
   a.add(b).output();
   cout << "\ndifference = ";
   a.subtract(b).output();
   cout << "\nproduct = ";
   a.multiply(b).output();
   cout << "\nquotient = ";
   a.divide(b).output();
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

RationalNumber RationalNumber::add(const RationalNumber& r) const
{
   return { m_numerator * r.m_denominator
            + m_denominator * r.m_numerator,
            m_denominator * r.m_denominator };
}

RationalNumber RationalNumber::subtract(const RationalNumber& r) const
{
   return { m_numerator * r.m_denominator
            - m_denominator * r.m_numerator,
            m_denominator * r.m_denominator };
}

RationalNumber RationalNumber::multiply(const RationalNumber& r) const
{
   return { m_numerator * r.m_numerator,
            m_denominator * r.m_denominator };
}

RationalNumber  RationalNumber::divide(const RationalNumber& r) const
{
   return { m_numerator *  r.m_denominator,
            m_denominator * r.m_numerator };
}

void RationalNumber::output() const
{
   cout << '('
        << m_numerator
        << '/'
        << m_denominator
        << ')'
        << flush;
}

void RationalNumber::normalize()
{
   intmax_t divisor { gcd(m_numerator,m_denominator) };
   m_numerator = sign(m_numerator) * sign(m_denominator)
                 * abs(m_numerator) / divisor;
   m_denominator = abs(m_denominator) / divisor;
}

RationalNumber inputRationalNumber()
{
   intmax_t numerator { 0 },
            denominator { 1 };
   cout << "numerator: " << flush;
   cin >> numerator;
   do
   {
      cout << "denominator: " << flush;
      cin >> denominator;
      if (denominator == 0)
      {
         cerr << "Error, denominator may not be 0!"
              << endl;
      }
   } while (denominator == 0);
   return { numerator, denominator };
}
