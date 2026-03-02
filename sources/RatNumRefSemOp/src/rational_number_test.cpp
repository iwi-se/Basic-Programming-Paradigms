// rational_number_test.cpp by Ulrich Eisenecker, March 14, 2025

#include <sstream>
#include "rational_number.hpp"

TEST_CASE("constructor","[rational_number]")
{
   using namespace rational_number;
   // All constructor parameters are defaulted.
   RationalNumber r1 { };
   REQUIRE(r1.numerator()   == 0);
   REQUIRE(r1.denominator() == 1);
   // Last constructor parameter is defaulted.
   RationalNumber r2 { 1 };
   REQUIRE(r2.numerator()   == 1);
   REQUIRE(r2.denominator() == 1);
   // All constructor parameters are explicitly provided.
   RationalNumber r3 { 2,1 };
   REQUIRE(r3.numerator()   == 2);
   REQUIRE(r3.denominator() == 1);
   // After construction a rational number is in its canonical form.
   RationalNumber r4 { -2 * 3 * 5, -2 * 3 * 7 };
   REQUIRE(r4.numerator()   == 5);
   REQUIRE(r4.denominator() == 7);
}

TEST_CASE("arithmetic methods","[rational_number]")
{
   using namespace rational_number;
   RationalNumber a { 4,7 },
                  b { 2,7 };
   SECTION("add")
   {
      a.add(b);
      REQUIRE(a.numerator() == 6);
      REQUIRE(a.denominator() == 7);
   }
   SECTION("subtract")
   {
      a.subtract(b);
      REQUIRE(a.numerator() == 2);
      REQUIRE(a.denominator() == 7);
   }
   SECTION("multiply")
   {
      a.multiply(b);
      REQUIRE(a.numerator() == 8);
      REQUIRE(a.denominator() == 49);
   }
   SECTION("divide")
   {
      a.divide(b);
      REQUIRE(a.numerator() == 2);
      REQUIRE(a.denominator() == 1);
   }
}

TEST_CASE("output","[rational_number]")
{
   using namespace std;
   using namespace rational_number;
   // String stream for serializing correct rational numbers
   ostringstream oss { };
   SECTION("serialize 1")
   {
      RationalNumber { }.output(oss);
      REQUIRE(oss.str() == "(0/1)");
   }
   SECTION("serialize 2")
   {
      RationalNumber { 2 }.output(oss);
      REQUIRE(oss.str() == "(2/1)");
   }
   SECTION("serialize 3")
   {
      RationalNumber { 2 * 3 * 5,3 * 5 * 7 }.output(oss);
      REQUIRE(oss.str() == "(2/7)");
   }
   SECTION("serialize 4")
   {
      RationalNumber { 2 * 3 * 5,-3 * 5 * 7 }.output(oss);
      REQUIRE(oss.str() == "(-2/7)");
   }
   SECTION("serialize 5")
   {
      RationalNumber { -2 * 3 * 5,3 * 5 * 7 }.output(oss);
      REQUIRE(oss.str() == "(-2/7)");
   }
   SECTION("serialize 6")
   {
      RationalNumber { -2 * 3 * 5,-3 * 5 * 7 }.output(oss);
      REQUIRE(oss.str() == "(2/7)");
   }
   SECTION("serialize 7")
   {
      RationalNumber { 2,5 }.output(oss);
      RationalNumber { 3,-7 }.output(oss);
      RationalNumber { -11,13 }.output(oss);
      RationalNumber { -17,-19 }.output(oss);
      REQUIRE(oss.str() == "(2/5)(-3/7)(-11/13)(17/19)");
   }
}

TEST_CASE("input","[rational_number]")
{
   using namespace std;
   using namespace rational_number;
   // String stream with exact and slightly varied serialized rational numbers.
   // Partially, a robustness test.
   // RationalNumber::input(istream&) does nit call normalize()!
   istringstream iss
      { "(1/2)(-1/2) (1/-2)   (-1/-2) (  2/  4)  (   -2 /   -4)  (0/0)" };
   RationalNumber r;
   // (1/2) --> (1/2)
   r.input(iss);
   REQUIRE(r.numerator()   ==  1);
   REQUIRE(r.denominator() ==  2);
   // (-1/2) --> (-1/2)
   r.input(iss);
   REQUIRE(r.numerator()   == -1);
   REQUIRE(r.denominator() ==  2);
   // (1/-2) --> (1/-2)
   r.input(iss);
   REQUIRE(r.numerator()   ==  1);
   REQUIRE(r.denominator() == -2);
   // (-1/-2) --> (-1/-2)
   r.input(iss);
   REQUIRE(r.numerator()   == -1);
   REQUIRE(r.denominator() == -2);
   // (  2/  4) --> (2/4)
   r.input(iss);
   REQUIRE(r.numerator()   ==  2);
   REQUIRE(r.denominator() ==  4);
   // (  -2 /   -4) --> (-2/-4)
   r.input(iss);
   REQUIRE(r.numerator()   == -2);
   REQUIRE(r.denominator() == -4);
   // (0/0) --> (0/0)
   r.input(iss);
   REQUIRE(r.numerator()   ==  0);
   REQUIRE(r.denominator() ==  0);
}

TEST_CASE("toLongDouble","[rational_number]")
{
   using namespace rational_number;
   RationalNumber r { -22, -7 };
   REQUIRE_THAT(r.toLongDouble(),Catch::Matchers::WithinAbs(3.14285,0.0005));
}
