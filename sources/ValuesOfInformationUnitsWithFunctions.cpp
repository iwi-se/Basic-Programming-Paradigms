// ValuesOfInformationUnitsWithFunctions by Ulrich Eisenecker, August 8, 2024

#include <iostream>
using namespace std;

int inputCardinality()
{
   int cardinality { };
   do
   {
      cout << "Cardinality of information unit (must be >= 2): "
           << flush;
      cin >> cardinality;
      if (cardinality < 2)
      {
         cout << "Illegal value – please, retry!"  
              << endl;
      }
   }
   while (cardinality < 2);
   return cardinality;
}

int inputNumberOfInformationUnits()
{
   int number { };
   do
   {
      cout << "Number of information units (must be >= 1): "
           << flush;
      cin >> number;
      if (number < 1)
      {
         cout << "Illegal value – please, retry!"  
              << endl;
      }
   }
   while (number < 1);
   return number;
}

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

void outputRepresentableValues(int values)
{
   cout << values 
        << " different values can be represented."
        << endl;
}

int main()
{
    int cardinality { inputCardinality() };
    int number { inputNumberOfInformationUnits() };
    int values { calculateRepresentableValues(cardinality,number) };
    outputRepresentableValues(values);
 return 0;
}
