// Sizeof by Ulrich Eisenecker, November 3, 2021

#include <climits> // because of CHAR_BIT
#include <iostream>
using namespace std;

int main()
{
   cout << "A byte has " << CHAR_BIT 
        << " bit on this platform."
        << endl;
   // cout << "sizeof(void); " << sizeof(void) << endl; 
   // uncommenting previous line causes an error, 
   // because void is an incomplete type
   cout << "sizeof(-.0e-42f): " << sizeof(-.0e-42f) << endl;
   cout << "sizeof(1/0.0): " << sizeof(1 / 0.0) << endl;
   cout << "sizeof(long double): " << sizeof(long double) << endl;
   size_t size { 0uz };
   cout << "sizeof(size): " << sizeof(size) << endl;
}
