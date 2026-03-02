// Grades.cpp by Ulrich Eisenecker, April 23, 2021

#include <iostream>
#include <string> // because of string
using namespace std;

enum class PhDGrade
{
   non_sufficit,
   rite,
   cum_laude,
   magna_cum_laude,
   summa_cum_laude
};    

[[nodiscard]] string to_string(const PhDGrade& grade)
{
   string name { };
   switch (grade)
   {
      using enum PhDGrade;
      case summa_cum_laude: name = "summa cum laude"s; break;
      case magna_cum_laude: name = "magna cum laude"s; break;
      case cum_laude      : name = "cum laude"s; break;
      case rite           : name = "rite"s; break;
      case non_sufficit   : name = "non sufficit"s; break;
   }
   return name;
}

int main()
{
  PhDGrade alexGrade { PhDGrade::rite },
           jordansGrade { PhDGrade::summa_cum_laude };
  cout << boolalpha
       << "Is Alex' grade better than Jordan's grade? "
       << (alexGrade > jordansGrade)
       << endl;


  alexGrade = PhDGrade::cum_laude;
  jordansGrade = PhDGrade::non_sufficit;

  cout << "alexGrade = " 
       << to_string(alexGrade)
       << endl
       << "jordansGrade = "
       << to_string(jordansGrade)
       << endl;
 }
