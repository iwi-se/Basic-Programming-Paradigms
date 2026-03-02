// rational_number_operators_test.cpp by Ulrich Eisenecker, March 17, 2025
// Using Catch2 in a modern way.

#include <catch2/catch_test_macros.hpp>

#include <sstream>
#include "rational_number.hpp"
#include "rational_number_operators.hpp"

TEST_CASE("operator","[rational_number_operators]")
{
   using namespace rational_number;
   RationalNumber a {  1,-5 },
                  b { -2, 3 };
   SECTION("operator+")
   {
      SECTION("RationalNumber + RationalNumber")
      {
         RationalNumber r { a + b };
         REQUIRE(r.numerator()   == -13);
         REQUIRE(r.denominator() ==  15);
      }
      SECTION("RationalNumber + int")
      {
         RationalNumber r { a + 2 };
         REQUIRE(r.numerator()   == 9);
         REQUIRE(r.denominator() == 5);
      }
      SECTION("int + RationalNumber")
      {
         RationalNumber r { 3 + b };
         REQUIRE(r.numerator()   == 7);
         REQUIRE(r.denominator() == 3);
      }
   }
   SECTION("operator-")
   {
      SECTION("RationalNumber - RationalNumber")
      {
         RationalNumber r { a - b };
         REQUIRE(r.numerator()   ==  7);
         REQUIRE(r.denominator() == 15);
      }
      SECTION("RationalNumber - int")
      {
         RationalNumber r { a - 2 };
         REQUIRE(r.numerator()   == -11);
         REQUIRE(r.denominator() ==   5);
      }
      SECTION("int - RationalNumber")
      {
         RationalNumber r { 3 - b };
         REQUIRE(r.numerator()   == 11);
         REQUIRE(r.denominator() ==  3);
      }
   }
   SECTION("operator*")
   {
      SECTION("RationalNumber * RationalNumber")
      {
         RationalNumber r { a * b };
         REQUIRE(r.numerator()   ==  2);
         REQUIRE(r.denominator() == 15);
      }
      SECTION("RationalNumber * int")
      {
         RationalNumber r { a * 2 };
         REQUIRE(r.numerator()   == -2);
         REQUIRE(r.denominator() ==  5);
      }
      SECTION("int * RationalNumber")
      {
         RationalNumber r { 3 * b };
         REQUIRE(r.numerator()   == -2);
         REQUIRE(r.denominator() ==  1);
      }
   }
   SECTION("operator/")
   {
      SECTION("RationalNumber / RationalNumber")
      {
         RationalNumber r { a / b };
         REQUIRE(r.numerator()   ==  3);
         REQUIRE(r.denominator() == 10);
      }
      SECTION("RationalNumber / int")
      {
         RationalNumber r { a / 2 };
         REQUIRE(r.numerator()   == -1);
         REQUIRE(r.denominator() == 10);
      }
      SECTION("int / RationalNumber")
      {
         RationalNumber r { 3 / b };
         REQUIRE(r.numerator()   == -9);
         REQUIRE(r.denominator() ==  2);
      }
   }
}

TEST_CASE("operator<<","[rational_number_operators]")
{
   using namespace rational_number;
   std::ostringstream oss;
   RationalNumber r { 24,7 };
   oss << r;
   REQUIRE(oss.str() == "(24/7)");
}

TEST_CASE("operator>>","[rational_number_operators]")
{
   using namespace rational_number;
   std::istringstream iss { "(24/7)" };
   RationalNumber r { };
   iss >> r;
   REQUIRE(r.numerator()   == 24);
   REQUIRE(r.denominator() ==  7);
}
