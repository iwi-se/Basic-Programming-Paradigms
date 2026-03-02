// ReturnVoidImproved by Ulrich Eisenecker, April 8, 2021

#include <algorithm> // because of swap()
#include <iostream>
#include <string> // because of string
using namespace std;

void reverseString2(string & s)
{
   string::size_type l { s.length() };
   if (l < 2)
      return;
   for (string::size_type i { 0 },
        m { l  / 2 - 1 }; 
        i <= m; ++i)
   {
      swap(s.at(i),s.at(l - i - 1));
   }
}

int main()
{
   string someString { };
   cout << "String: "
        << flush;
   cin >> someString;
   reverseString2(someString);

   cout << "Reversed string = "
        << someString
        << endl;
}
