// ReturnValue2ndVersion by Ulrich Eisenecker, February 6, 2022

#include <algorithm> // because of swap()
#include <iostream>
#include <string> // because of string
using namespace std;

[[nodiscard]] string reverseString5(string s)
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
   cout << "Reversed string = "
        << reverseString5("Hello"s)
        << endl;
}
