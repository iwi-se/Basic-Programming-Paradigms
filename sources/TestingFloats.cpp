// TestingFloats by Ulrich Eisenecker, November 3 ,2021

#include <cmath> // because of fabs()
#include <iostream>
using namespace std;

int main()
{
   double d { 0.4 + 0.4 + 0.4 };
   cout << boolalpha
        << "d == 1.2: " << (d == 1.2) << endl;
   cout << "1.1999 < d && d < 1.2001: " << (1.1999 < d && d < 1.2001) << endl;
   cout << "fabs(d - 1.2) < 0.0002: " << (fabs(d - 1.2) < 0.0002) << endl;
}
