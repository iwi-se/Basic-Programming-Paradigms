// ReturnValue by Ulrich Eisenecker, April 8, 2021

#include <algorithm> // because of swap()
#include <iostream>
#include <string> // because of string
using namespace std;

[[nodiscard]] string reverseString4(const string & s)
{
   string result { s };
   string::size_type l { result.length() };
   if (l > 1)
   {
      for (string::size_type i { 0 },
           m { l  / 2 - 1 }; 
           i <= m; ++i)
      {
         swap(result.at(i),result.at(l - i - 1));
      }
   }
   return result;
}

int main()
{
   cout << "Reversed string = "
        << reverseString4("Hello"s)
        << endl;
}
