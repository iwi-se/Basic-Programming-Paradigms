#include <numeric> // Because of gcd().
#include <iostream>
using namespace std;

#include "math_helper.hpp"
using namespace math_helper;

#include "rational_number.hpp"

namespace rational_number
{
   RationalNumber::RationalNumber(const intmax_t& n, const intmax_t& d):
      m_numerator { n }, m_denominator { d }
   {
      normalize();
   }

   RationalNumber& RationalNumber::numerator(const intmax_t& n)
   {
      m_numerator = n;
      normalize();
      return *this;
   }

   RationalNumber& RationalNumber::denominator(const intmax_t& d)
   {
      m_denominator = d;
      normalize();
      return *this;
   }

   RationalNumber&  RationalNumber::add(RationalNumber r)
   {
      m_numerator = m_numerator * r.denominator() 
                    + m_denominator * r.numerator();
      m_denominator = m_denominator * r.denominator();
      normalize();
      return *this;
   }

   RationalNumber& RationalNumber::subtract(RationalNumber r)
   {
      m_numerator = m_numerator * r.denominator() 
                    - m_denominator * r.numerator();
      m_denominator = m_denominator * r.denominator();
      normalize();
      return *this;
   }

   RationalNumber& RationalNumber::multiply(const RationalNumber r)
   {
      m_numerator = m_numerator * r.numerator();
      m_denominator = m_denominator *  r.denominator();
      normalize();
      return *this;
   }

   RationalNumber& RationalNumber::divide(RationalNumber r)
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
      intmax_t divisor = gcd(m_numerator,m_denominator);
      m_numerator = sign(m_numerator) * sign(m_denominator) 
                    * abs(m_numerator) / divisor;
      m_denominator = abs(m_denominator) / divisor;
   }
}
