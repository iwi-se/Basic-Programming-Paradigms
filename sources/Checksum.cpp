// Checksum by Ulrich Eisenecker, August 2, 2020

#include <iostream>
using namespace std;

unsigned long checksum(unsigned long number)
{
   if (number % 10 == number)
      return number;
   else 
      return (number % 10) + checksum(number / 10);
}

int main()
{
   cout << "Natural number: " << flush;
   unsigned long number { };
   cin >> number;
   cout << "Checksum = " << checksum(number) << endl;
   return 0;
}
