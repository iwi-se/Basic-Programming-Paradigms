// ChecksumFunction by Ulrich Eisenecker, November 24 2023

#include <iostream>
using namespace std;

unsigned int checksum(unsigned int number)
{
   unsigned int result { };
   while (number > 0)
   {
      result = result + number % 10;
      number = number / 10;
   }
   return result;
}

int main()
{
   cout << "Natural number: " << flush;
   unsigned int number { };
   cin >> number;
   cout << "Checksum = " << checksum(number) << endl;
}
