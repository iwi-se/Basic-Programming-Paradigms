// References by Ulrich Eisenecker, March 18, 2021

#include <iostream>
using namespace std;

int main()
{
   double d { 1.0 / 3.0 };
   double & rd = d;
   cout << "d:   " << d << endl
        << "rd:  " << rd << endl;
   rd *= 3.0; 
   cout << "d:   " << d << endl
        << "rd:  " << rd << endl;
   double & rd2 { rd };
   cout << "rd2: " << rd2 << endl;
   double * pd  { &d  },
          * prd { &rd };
   cout << boolalpha
        << "pd == prd: "
        << (pd == prd) << endl;
}
