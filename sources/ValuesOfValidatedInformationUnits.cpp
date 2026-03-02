// ValuesOfEightValidatedInformationUnits by Ulrich Eisenecker, July 15, 2020

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
   cout << cardinality * cardinality * 
           cardinality * cardinality * 
           cardinality * cardinality * 
           cardinality * cardinality 
        << " different values can be represented."
        << endl;
   return 0;
}
