// CallByPointer by Ulrich Eisenecker, April 6, 2021

#include <iostream>
#include <string> // because of string
using namespace std;

void prependSalutation(string * name)
{
   cout << "Entering prependSalutation() ... \n"
        << "Memory address of name = " 
        << (&name)
        << endl
        << "Content of name = "
        << name // This is a memory address!
        << endl
        << "Value of *name = "
        << (*name)
        << endl;
   *name = "Hi, " + *name;
   cout << "New value of *name = "
        << (*name)
        << "\n... leaving prependSalutation()"
        << endl;
}

int main()
{
   string yourName { };
   cout << "In main() ...\n"
        << endl
        << "Your name: "
        << flush;
   cin >> yourName;
   cout << "Memory address of yourName = "
        << (&yourName)
        << endl
        << "Value of yourName = "
        << yourName
        << endl;

   prependSalutation(&yourName);

   cout << "... back in main()\n"
        << "Memory address of yourName = "
        << (&yourName)
        << endl
        << "Value of yourName = "
        << yourName
        << endl;
}
