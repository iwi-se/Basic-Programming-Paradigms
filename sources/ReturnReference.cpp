// ReturnReference by Ulrich Eisenecker, April 8, 2021

#include <algorithm> // because of swap()
#include <iostream>
#include <string> // because of string
using namespace std;

string& reverseString3(string & s)
{
   string::size_type l { s.length() };
   if (l > 1)
   {
      for (string::size_type i { 0 },
           m { l  / 2 - 1 }; 
           i <= m; ++i)
      {
         swap(s.at(i),s.at(l - i - 1));
      }
   }
   return s;
}

int main()
{
   string someString { };
   cout << "String: "
        << flush;
   cin >> someString;

   cout << "Reversed string = "
        << reverseString3(someString)
        << endl;
}
