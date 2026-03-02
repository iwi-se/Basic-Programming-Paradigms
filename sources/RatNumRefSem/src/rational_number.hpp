/*! \file rational_number.hpp
 *
 *  Types and functions related to rational numbers.
 *
 *  \author Ulrich Eisenecker
 *  \date May 27, 2021
 */

/*!
 * Include gard for rational_number.hpp
 */
#ifndef RATIONAL_NUMBER_HPP
#define RATIONAL_NUMBER_HPP

#include <cstdint> // Because of intmax_t

/*! Namespace for types and functions related to rational numbers.
 */
namespace rational_number
{
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
         RationalNumber(const std::intmax_t& n = 0, const std::intmax_t& d = 1);
         /*! Returns m_numerator as reference to const.
          */
         [[nodiscard]] const std::intmax_t& numerator() const
         {
            return m_numerator;
         }
         /*! Returns m_denominator as reference to const.
          */
         [[nodiscard]] const std::intmax_t& denominator() const
         {
            return m_denominator;
         }
         /*! Sets m_numerator to n,
          *  normalizes rational number,
          *  and returns *this as reference.
          */
         RationalNumber& numerator(const std::intmax_t& n);
         /*! Sets m_denominator to d,
          *  normalizes rational number,
          *  and returns *this as reference.
          */
         RationalNumber& denominator(const std::intmax_t& d);
         /*! Adds rational numbers *this and r,
          *  stores result in *this,
          *  and return *this as reference.
          */
         RationalNumber& add(RationalNumber r);
         /*! Subtracts rational number r from *this,
          *  stores result in *this,
          *  and return *this as reference.
          */
         RationalNumber& subtract(RationalNumber r);
         /*! Multiplies rational numbers *this and r,
          *  stores result in *this,
          *  and return *this as reference.
          */
         RationalNumber& multiply(RationalNumber r);
         /*! Divides rational numbers *this by r,
          *  stores result in *this,
          *  and return *this as reference.
          */
         RationalNumber& divide(RationalNumber r);
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
         std::intmax_t m_numerator { 0 },
         /*! Holds denominator of rational number.
          *  By default, denominator is initialized to 1.
          */
                       m_denominator { 1 };
   };
}
#endif // RATIONAL_NUMBER_HPP
