// CallByValue by Ulrich Eisenecker, April 1, 2021

#include <iostream>
using namespace std;

void someFunction(double number)
{
   cout << "Entering someFunction() ... \n"
   << "Memory address of number = " 
        << (&number)
        << endl
        << "Value of number = "
        << number
   << endl;
   number = number * 2.0;
   cout << "New value of number = "
   << number
   << "\n... leaving someFunction()"
   << endl;
}

int main()
{
   double number { 21.0 };
   cout << "In main() ...\n"
   << "Memory address of number = "
        << (&number)
   << endl
   << "Value of number = "
   << number
   << endl;

   someFunction(number);

   cout << "... back in main()\n"
   << "Memory address of number = "
        << (&number)
   << endl
   << "Value of number = "
   << number
   << endl;
}
