// TypeInformation by Ulrich Eisenecker, August 12, 2024

#include <cstddef>     // Because of std::nullptr_t.
#include <iostream>
#include <type_traits> // Because of is_arithmetic_v<>, is_integral_v<>, 
                       // is_unsigned_v<>, is_signed_v<>,  
                       // is_floating_point_v<>, is_same_v<>.
using namespace std;

int main()
{
   cout << boolalpha
        << "is_arithmetic<>"
        << endl   
        << is_arithmetic_v<bool> << endl
        << is_arithmetic_v<char> << endl
        << is_arithmetic_v<int> << endl
        << is_arithmetic_v<double> << endl
        << is_arithmetic_v<nullptr_t> << endl;

   
   cout << "\nis_integral_v<>" << endl
        << is_integral_v<bool> << endl
        << is_integral_v<char> << endl
        << is_integral_v<int> << endl
        << is_integral_v<double> << endl
        << is_integral_v<nullptr_t> << endl;

   cout << "\nis_unsigned_v<>" << endl
        << is_unsigned_v<bool> << endl
        << is_unsigned_v<char> << endl
        << is_unsigned_v<int> << endl
        << is_unsigned_v<double> << endl
        << is_unsigned_v<nullptr_t> << endl;

   cout << "\nis_signed_v<>" << endl
        << is_signed_v<bool> << endl
        << is_signed_v<char> << endl
        << is_signed_v<int> << endl
        << is_signed_v<double> << endl
        << is_signed_v<nullptr_t> << endl;

   cout << "\nis_floating_point_v<>" << endl
        << is_floating_point_v<bool> << endl
        << is_floating_point_v<char> << endl
        << is_floating_point_v<int> << endl
        << is_floating_point_v<double> << endl
        << is_floating_point_v<nullptr_t> << endl;

   cout << "\nis_same_v<>" << endl
        << is_same_v<bool,bool> << endl
        << is_same_v<bool,int> << endl;

   cout << "\nis_same_v<>" << endl
        << is_same_v<int,signed int> << endl;
}
