/*! \file RationalNumberClassReferenceSemantics.cpp
 *
 *  Implements arithmetic for rational numbers
 *  represented by a class
 *  using reference semantics.
 *
 *  \author Ulrich Eisenecker
 *  \date December 14, 2023 
 */

#include <cmath> // Because of abs().
#include <cstdint> // Because of intmax_t.
#include <iostream>
#include <numeric> // Because of gcd().

using namespace std;

/*! Returns -1 if n < 0, 0 if n == 0, +1 if n > 0.
 */
[[nodiscard]] intmax_t sign(const intmax_t& n);

/*! Represents rational number as class.
 */
class RationalNumber
{
   public:
      /*! Constructs a normalized RationalNumber exemplar 
       *  with n for m_numerator and d for d_denominator;
       *  default value for n is 0, 
       *  default value for d is 1.
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
      /*! Sets m_numerator to n,
       *  normalizes rational number,
       *  and returns *this as reference.
       */
      RationalNumber& numerator(const intmax_t& n)
      {
         m_numerator = n;
         normalize();
         return *this;
      }
      /*! Sets m_denominator to d,
       *  normalizes rational number,
       *  and returns *this as reference.
       */
      RationalNumber& denominator(const intmax_t& d)
      {
         m_denominator = d;
         normalize();
         return *this;
      }
      /*! Adds rational numbers *this and r,
       *  stores result in *this,
       *  and return *this as reference.
       */
      RationalNumber& add(const RationalNumber& r);
      /*! Subtracts rational number r from *this,
       *  stores result in *this,
       *  and return *this as reference.
       */
      RationalNumber& subtract(const RationalNumber& r);
      /*! Multiplies rational numbers *this and r,
       *  stores result in *this,
       *  and return *this as reference.
       */
      RationalNumber& multiply(const RationalNumber& r);
      /*! Divides rational numbers *this by r,
       *  stores result in *this,
       *  and return *this as reference.
       */
      RationalNumber& divide(const RationalNumber& r);
      /*! Inputs rational number from cin
       *  and returns *this as reference.
       */
      RationalNumber& input();
      /*! Outputs rational number to cout
       *  and returns *this as reference.
       */
      RationalNumber& output();
   private:
      /*! Normalizes rational number, 
       *   i.e., canonical form and m_denominator > 0.
       */
      void normalize();
      /*! Holds numerator of rational number.
       *  By default, numerator is initialized to 0.
       */
      intmax_t m_numerator { 0 },
      /*! Holds denominator of rational number.
       *  By default, denominator is initialized to 1.
       */
               m_denominator { 1 };
};

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
   RationalNumber a { }, b { }, c { };
   cout << "Enter 1st rational number\n";
   a.input();
   cout << "\nEnter 2nd rational number\n";
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

RationalNumber& RationalNumber::add(const RationalNumber& r)
{
   m_numerator = m_numerator * r.denominator() 
                 + m_denominator * r.numerator();
   m_denominator = m_denominator * r.denominator();
   normalize();
   return *this;
}

RationalNumber& RationalNumber::subtract(const RationalNumber& r)
{
   m_numerator = m_numerator * r.denominator() 
                 - m_denominator * r.numerator();
   m_denominator = m_denominator * r.denominator();
   normalize();
   return *this;
}

RationalNumber& RationalNumber::multiply(const RationalNumber& r)
{
   m_numerator = m_numerator * r.numerator();
   m_denominator = m_denominator *  r.denominator();
   normalize();
   return *this;
}

RationalNumber& RationalNumber::divide(const RationalNumber& r)
{
   m_numerator = m_numerator *  r.denominator();
   m_denominator = m_denominator * r.numerator();
   normalize();
   return *this;
}

RationalNumber& RationalNumber::input()
{
   cout << "numerator: " << flush;
   cin >> m_numerator;
   do
   {
      cout << "denominator: " << flush;
      cin >> m_denominator;
      if (m_denominator == 0)
      {
         cerr << "Error, denominator may not be 0!" 
              << endl;
      }
   } while (m_denominator == 0);
   normalize();
   return *this;
}

RationalNumber& RationalNumber::output()
{
   cout << '('
        << m_numerator
        << '/'
        << m_denominator
        << ')'
        << flush;
   return *this;
}

void RationalNumber::normalize()
{
   intmax_t divisor { gcd(m_numerator,m_denominator) };
   m_numerator = sign(m_numerator) * sign(m_denominator) 
                 * abs(m_numerator) / divisor;
   m_denominator = abs(m_denominator) / divisor;
}
