// Buddy.cpp by Ulrich Eisenecker, May 12, 2021

#include <iostream>
#include <string> // Because of string.
using namespace std;

class Buddy
{
   public:
      Buddy(const string& n):m_name { n }
      {
         cout << "Buddy::Buddy(const string&)" << endl;
      }
      ~Buddy()
      {
         cout << "Buddy::˜Buddy()" << endl;
      }
      [[nodiscard]] const string& name() const
      {
         cout << "const string& Buddy::name() const" << endl;
         return m_name;
      }      
      void name(const string& n)
      {
         cout << "void Buddy::name(const string&)" << endl;
         m_name = n;
      }
   private:
      string m_name { };
};

int main()
{
   Buddy b { "Blake" };
   cout << b.name() << endl;
   b.name("Taylor");
   cout << b.name() << endl;
}
