// NumericLimits by Ulrich Eisenecker, March 15, 2021

#include <cstddef> // Because of std::nullptr_t.
#include <iostream>
#include <limits> // Because of numeric_limits<>.
using namespace std;

int main()
{
   cout << boolalpha;
        
   cout << "nullptr_t" << endl
        << numeric_limits<nullptr_t>::is_specialized << endl
        << numeric_limits<nullptr_t>::is_exact << endl
        << numeric_limits<nullptr_t>::min() << endl
        << numeric_limits<nullptr_t>::max() << endl
        << numeric_limits<nullptr_t>::epsilon() << endl;

   cout << "\nint" << endl
        << numeric_limits<int>::is_specialized << endl
        << numeric_limits<int>::is_exact << endl
        << numeric_limits<int>::lowest() << endl
        << numeric_limits<int>::min() << endl
        << numeric_limits<int>::max() << endl
        << numeric_limits<int>::epsilon() << endl;

   cout << "\ndouble" << endl
        << numeric_limits<double>::is_specialized << endl
        << numeric_limits<double>::is_exact << endl
	<< numeric_limits<double>::lowest() << endl
        << numeric_limits<double>::min() << endl
        << numeric_limits<double>::max() << endl  
        << numeric_limits<double>::epsilon() << endl;
}
