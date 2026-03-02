// Booleans by Ulrich Eisenecker, February 17,2021

#include <iostream>
using namespace std;

void printTruthTableNot()
{
   cout << "\nlogical not" << endl;
   for (bool p : {false,true})
   {
      bool r { !p };
      cout << p
           << "\t-->\t" 
           << r << endl; 
   }
}

void printTruthTableAnd()
{
   cout << "\nlogical and" << endl;
   for (auto p : {false,true})
   {
      for (auto q : {false,true})
      {
         auto r { p && q };
         cout << p << '\t'
              << q << '\t'
              << " -->\t"
              << r << endl;
      }
   }
}

void printTruthTableInclusiveOr()
{
   cout << "\nlogical or" << endl;
   for (auto p : {false,true})
   {
      for (bool q : {false,true})
      {
         auto r { p || q };
         cout << p << '\t'
              << q << '\t'
              << " -->\t"
              << r << endl;
      }
   }
}

void printConversionsBoolToInt()
{
   cout << "\nconverting bool to int" << endl;
   bool p { false };
   int i { p };
   cout << "bool value " << p
        << " becomes int value " << i
        << endl;
   auto q { true };
   i = q;
   cout << "bool value " << q
        << " becomes int value " << i
        << endl;
}

void printConversionsIntToBool()
{
   cout << "\nconverting int to bool" << endl;
   for (int i { -2 }; i <= 2; ++i)
   {
      bool p = i; // calling type conversion constructor
      cout << "int value " << i
           << " becomes bool value " << p
           << endl;
   }
}

int main()
{
   // boolalpha causes output of "false" or "true"
   cout << boolalpha; 
   printTruthTableNot();
   
   // noboolalpha causes output of 0 or 1
   cout << noboolalpha;
   printTruthTableAnd();

   // switching back to "false" or "true"
   cout << boolalpha;
   printTruthTableInclusiveOr();

   printConversionsBoolToInt();
   printConversionsIntToBool();
}
