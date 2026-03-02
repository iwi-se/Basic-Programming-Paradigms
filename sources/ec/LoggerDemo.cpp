// LoggerDemo.cpp by Ulrich Eisenecker, January 5, 2024

#include <iostream>
#include <source_location>
#include <string>
#include <cstdint> // Because of intmax_t

using namespace std;

constexpr bool loggingActive { false };

//Logger is for Logging only
class Logger
{
   public:
      Logger(const string& arguments = "",
             string name = source_location::current().function_name()
            ):
                m_name { name },
                m_arguments { arguments}
      {
         if constexpr (loggingActive)
         {
            string indentation(++m_activeFunctions,'>');
            cout << indentation << ' '
                 << m_name << " : " 
                 << m_arguments << endl;
                 
         }
      }
      ~Logger()
      {
         if constexpr (loggingActive)
         {
            string indentation(m_activeFunctions--,'<');
            cout << indentation << ' '
                 << m_name << " : " 
                 << m_arguments << endl;
         }
      }
   private:
      static inline size_t m_activeFunctions { 0 };
      string m_name,
             m_arguments;
};

intmax_t factorial(intmax_t n)
{
   Logger log {to_string(n) };
   if (n == 0)
   {
      return 1;
   }
   else
   {
      return n * factorial(n - 1);
   }
}

int main()
{
   Logger log {};
   intmax_t n;
   cin >> n;
   cout << factorial(n) << endl;
}
