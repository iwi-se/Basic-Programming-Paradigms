// ChecksumMain by Ulrich Eisenecker, November 24, 2023

#include <iostream>
using namespace std;

int main()
{
   cout << "Natural number: " << flush;
   unsigned int number { };
   cin >> number;
   unsigned int checksum { };
   while (number > 0)
   {
      checksum = checksum + number % 10;
      number = number / 10;
   }
   cout << "Checksum = " << checksum << endl;
}
