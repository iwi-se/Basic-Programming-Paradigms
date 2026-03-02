// MoreOverloading_C by Ulrich Eisenecker, April 19, 2021

#include <iostream>

using namespace std;

int timesTwo(int number)
{
   cout << "timesTwo(int) ";
   return number << 1;
}

double timesTwo(const double& number)
{
   cout << "timesTwo(const double&) ";
   return number * 2.0;
}

double timesTwo(double& number)
{
   cout << "timesTwo(double&) ";
   return number * 2.0;
} 

double timesTwo(double* number)
{
   cout << "timesTwo(double*) ";
   return 2.0 * *number;
}

double timesTwo(const double* number)
{
   cout << "timesTwo(const double*) ";
   return (*number) * 2.0;
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
        << timesTwo(&d)
        << endl
        << timesTwo(&dc)
        << endl;
}
