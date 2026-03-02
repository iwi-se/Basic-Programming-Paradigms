// Infinity_NaN by Ulrich Eisenecker, November 3, 2021

#include <cmath> // because of sqrt() and macros INFINITY and NAN
#include <iostream>
using namespace std;

int main()
{
   double d { 1.0 / 0.0 };
   cout << d << endl;
   cout << boolalpha
        << "d == INFINITY: " << (d == INFINITY) << endl;
   d = sqrt(-1.0);
   cout << d << endl;
   cout << "d == NAN: " << (d == NAN) << endl;
   cout << "NAN == NAN: " << (NAN == NAN) << endl
        << "NAN != NAN: " << (NAN != NAN) << endl;
}

