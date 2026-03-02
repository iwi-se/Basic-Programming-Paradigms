// MoreOverloading_A by Ulrich Eisenecker, April 18, 2021

#include <iostream>

using namespace std;

int timesTwo(int number)
{
   cout << "timesTwo(int) ";
   return number << 1;
}

int main()
{
   double d { 3.0 };
   const double dc { 4.0 };
   cout << timesTwo(1)
        << endl
        << timesTwo(2.0)
        << endl
        << timesTwo(d)
        << endl
        << timesTwo(dc)
        << endl;
}
