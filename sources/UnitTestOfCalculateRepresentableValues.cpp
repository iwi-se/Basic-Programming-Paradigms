// UnitTestOfCalculateRepresentableValues by Ulrich Eisenecker, August 8, 2024

#include <iostream>
using namespace std;

int calculateRepresentableValues(int cardinality,int number)
{
   int values { 1 };
   while (number > 0)
   {
      values = values * cardinality;
      number = number - 1;
   }
   return values;
}

int main()
{
   int passed { 0 };
   int failed { 0 };

   cout << "Unit testing of calculateRepresentableValues()\n" << endl;

   cout << "Test case \"Two smallest values\" ... " 
        << flush;
   if (calculateRepresentableValues(2,1) == 2)
   { 
      passed = passed + 1;
      cout << "passed." << endl;
   }
   else
   {
      failed = failed + 1;
      cout << "failed." << endl;
   }

   cout << "Test case \"One smallest, one larger value\" ... " 
        << flush;
   if (calculateRepresentableValues(2,4) == 16)
   { 
      passed = passed + 1;
      cout << "passed." << endl;
   }
   else
   {
      failed = failed + 1;
      cout << "failed." << endl;
   }

   cout << "Test case \"One larger, one smallest value\" ... " 
        << flush;
   if (calculateRepresentableValues(3,1) == 3)
   { 
      passed = passed + 1;
      cout << "passed." << endl;
   }
   else
   {
      failed = failed + 1;
      cout << "failed." << endl;
   }

   cout << "Test case \"Two larger values\" ... " 
        << flush;
   if (calculateRepresentableValues(3,4) == 81)
   { 
      passed = passed + 1;
      cout << "passed." << endl;
   }
   else
   {
      failed = failed + 1;
      cout << "failed." << endl;
   }

   cout << "\nTotal test cases:  " << (passed + failed) << endl
        << "Passed test cases: " << passed << endl
        << "Failed test cases: " << failed << endl;
}
