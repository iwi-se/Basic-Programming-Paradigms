// UnsignedVsSigned by Ulrich Eisenecker, March 1, 2021

#include <iostream>
using namespace std;

int main()
{
   // underflow and overflow for unsigned
   cout << "unsigned" << endl;
   unsigned u { 0 };
   cout << "lower bound:     " << u << endl;
   u = u - 1;
   cout << "lower bound - 1: " << u << endl;
   u = 0;
   u = ~u; // negate all bits of u
   cout << "upper bound:     " << u << endl;
   u = u + 1;
   cout << "upper bound + 1: " << u << endl;
   
   // underflow and overflow for signed
   cout << "signed" << endl;
   u = 0; u = ~u; u = u >> 1; u = ~u;
   signed s = u; // calling type conversion constructor
   cout << "lower bound:     " << s << endl;
   s = s - 1;
   cout << "lower bound - 1: " << s << endl;
   u = 0; u = ~u; u = u >> 1;
   s = u;
   cout << "upper bound:     " << s << endl;
   s = s + 1;
   cout << "upper bound + 1: " << s << endl;
}
