// ValuesOfInformationUnits by Ulrich Eisenecker, July 23, 2020

#include <iostream>
using namespace std;

int main()
{
   int cardinality;
   cout << "Cardinality of information unit (must be >= 2): "
        << flush;
   cin >> cardinality;
   if (cardinality < 2)
   {
      cerr << "Cardinality of information unit must be >= 2!\n" 
           << "Program terminated."
           << endl;
      return 1;
   }

   int number;
   cout << "Number of information units (must be >= 1): "
        << flush;
   cin >> number;
   if (number < 1)
   {
      cerr << "Number of information units must be >= 1!\n" 
           << "Program terminated."
           << endl;
      return 2;
   }

   int values = 1;
   while (number > 0)
   {
      values = values * cardinality;
      number = number - 1;
   }

   cout << values 
        << " different values can be represented."
        << endl;
   return 0;
}
