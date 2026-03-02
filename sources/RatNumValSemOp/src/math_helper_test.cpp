// math_helper_test.cpp by Ulrich Eisenecker, March 20, 2022

#include <cstdint>  // Because of intmax_t
#include <limits> // because of numeric_limits<>

#include "math_helper.hpp"

TEST_CASE("sign","[math_helper]")
{
   using namespace std;
   using namespace math_helper;
   // Testing smallest values.
   REQUIRE(sign(-1) == -1);
   REQUIRE(sign( 0) ==  0);
   REQUIRE(sign( 1) ==  1);
   // Testing largest values.
   intmax_t minValue { numeric_limits<intmax_t>::min() },
            maxValue { numeric_limits<intmax_t>::max() };
   REQUIRE(sign(minValue) == -1);
   REQUIRE(sign(maxValue) ==  1);
}
