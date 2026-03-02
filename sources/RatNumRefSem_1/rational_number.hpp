#include <cstdint> // Because of intmax_t.

class RationalNumber
{
   public:
      RationalNumber(const std::intmax_t& n = 0, const std::intmax_t& d = 1);
      [[nodiscard]] const std::intmax_t& numerator() const
      {
         return m_numerator;
      }
      [[nodiscard]] const std::intmax_t& denominator() const
      {
         return m_denominator;
      }
      RationalNumber& numerator(const std::intmax_t& n);
      RationalNumber& denominator(const std::intmax_t& d);
      RationalNumber& add(RationalNumber r);
      RationalNumber& subtract(RationalNumber r);
      RationalNumber& multiply(RationalNumber r);
      RationalNumber& divide(RationalNumber r);
      RationalNumber& input();
      RationalNumber& output();
   private:
      void normalize();
      std::intmax_t m_numerator { 0 },
                    m_denominator { 1 };
};
