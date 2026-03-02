#include "math_helper.hpp"

using namespace std;

namespace math_helper 
{
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
}
