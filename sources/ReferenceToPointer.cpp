// ReferenceToPointer by Ulrich Eisenecker, March 18, 2021

#include <iostream>
using namespace std;

int main()
{
   int * pi { new int { 42 } };
   cout << "*pi: " << (*pi) << endl;
   int *& rpi { pi };
   if (&pi == &rpi)
   {
      cout << "pi and rpi have the same address, "
	      "i.e., they are different names "
	      "for the same object." << endl;
   }
   else
   {
      cout << "Something is broken." << endl;
   }
   cout << "*rpi: " << (*rpi) << endl;
   delete pi;
   pi = nullptr;
   if (!rpi)
   {
      cout << "rpi == nullptr" << endl;
   }
   else
   {
      cout << (*rpi) << " (this should not happen)" << endl;
   }
   pi =  new int { 99 };
   cout << "*rpi: " << (*rpi) << endl;
   delete pi;
   pi = nullptr;
   if (!rpi)
   {
      cout << "rpi == nullptr" << endl;
   }
   else
   {
      cout << (*rpi) << " (this should not happen)" << endl;
   }
}
