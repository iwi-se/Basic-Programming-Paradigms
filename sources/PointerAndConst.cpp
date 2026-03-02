// PointerAndConst by Ulrich Eisenecker, March 18, 2021

#include <iostream>
using namespace std;

int main()
{
   int * pi { new int { 42 } };
   cout << "*pi: " << (*pi) << endl; 

   // pointer to const
   const int * pci1 { pi }; // pointer to const int
   int const * pci2 { pi }; // also pointer to const int
   cout << "*pci1: " << (*pci1) << endl; // Ok, using *pci1 as rvalue
   // (*pci2) = 99; // Error, pointer to const cannot be modified
   
   // const pointer
   int * const cpi { new int { 11 } }; // const pointer to int
   cout << "*cpi: " << (*cpi) << endl;
   (*cpi) = 99; // Ok, const pointer points to non-const int
   cout << "*cpi: " << (*cpi) << endl;
   delete cpi; // Ok, const pointer may be deleted!
   // cpi = nullptr; // Error, const pointer cannot be modified 
                     // --> invalid pointer
   
   // const pointer to const
   const int * const cpci1 { pi }; // const pointer to const int
   int const * const cpci2 { pi }; // also const pointer to const int
   // (*cpci1) = 99; // Error, const int cannot be modified
   // cpci1 = cpci2; // Error, const pointer cannot be modified
   // delete cpci1; // Bad idea! Dynamic object is owned by pi, not by cpci1
   // cpci1 = nullptr; // Error, const pointer cannot be modified 
                       // --> invalid pointer
   // cpci2 = nullptr; // Error, const pointer cannot be modified 
                       // --> invalid pointer
   
   delete pi; // Ok, *pi is owned by pi, thus it should be released by pi
   pi = nullptr; // Ok 
}
