// TypeInformationTabularForm by Ulrich Eisenecker, August 12,i 2024

#include <cstddef> // because of std::nullptr_t
#include <iomanip> // because of setw()
#include <iostream>
#include <type_traits> // because of is_arithmeti_vc_v<>, is_integral_V<>, 
                       // is_unsigned_v_v<>, is_signed_v_v<>,  
                       // is_floating_point_v_v<>
using namespace std;

void printLine()
{
    cout << "--------------------+----------+----------+----------+----------+----------\n";
}

int main()
{
   cout << boolalpha << endl;
   cout << "                    | bool     | char     | int      | double   | nullptr_t \n";
   printLine();
   cout << setw(19) << "is_arithmetic_v" << " | "
        << setw(8) << is_arithmetic_v<bool> << " | "
        << setw(8) << is_arithmetic_v<char> << " | "
        << setw(8) << is_arithmetic_v<int> << " | "
        << setw(8) << is_arithmetic_v<double> << " | "
        << setw(9) << is_arithmetic_v<nullptr_t> << endl;

   printLine();
   cout << setw(19) << "is_integral_v" << " | "
        << setw(8) << is_integral_v<bool> << " | "
        << setw(8) << is_integral_v<char> << " | "
        << setw(8) << is_integral_v<int> << " | "
        << setw(8) << is_integral_v<double> << " | "
        << setw(9) << is_integral_v<nullptr_t> << endl;

   printLine();
   cout << setw(19) << "is_unsigned_v" << " | "
        << setw(8) << is_unsigned_v<bool> << " | "
        << setw(8) << is_unsigned_v<char> << " | "
        << setw(8) << is_unsigned_v<int> << " | "
        << setw(8) << is_unsigned_v<double> << " | "
        << setw(9) << is_unsigned_v<nullptr_t> << endl;

   printLine();
   cout << setw(19) << "is_signed_v" << " | "
        << setw(8) << is_signed_v<bool> << " | "
        << setw(8) << is_signed_v<char> << " | "
        << setw(8) << is_signed_v<int> << " | "
        << setw(8) << is_signed_v<double> << " | "
        << setw(9) << is_signed_v<nullptr_t> << endl;

   printLine();
   cout << setw(19) << "is_floating_point_v" << " | "
        << setw(8) << is_floating_point_v<bool> << " | "
        << setw(8) << is_floating_point_v<char> << " | "
        << setw(8) << is_floating_point_v<int> << " | "
        << setw(8) << is_floating_point_v<double> << " | "
        << setw(9) << is_floating_point_v<nullptr_t> << endl;
}
