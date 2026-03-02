// Overloading by Ulrich Eisenecker, April 16, 2021

#include <iomanip> // because of fixed and setprecision()
#include <iostream>

using namespace std;

[[nodiscard]] 
   double estimatedRange(const double & remainingFuel,
                         const double & consumedFuel, 
                         const double & distanceTraveled);
[[nodiscard]] 
   double estimatedRange(const double & remainingFuel,
                         const double & consumedFuel);

int main()
{
   cout << fixed << setprecision(2)
        << "Estimated remaining range = "
        << estimatedRange(30.0,6.0) // arguments are liters 
        << " km\n"                  // and liter per 100 km
        << "Estimated remaining range = "
        << estimatedRange(15.0,12.0,200.0) // arguments are liters, 
                                           // liters, and km
        << " km"
        << endl;
}

double estimatedRange(const double & remainingFuel,
                      const double & consumedFuel, 
                      const double & distanceTraveled)
{
   return remainingFuel / (consumedFuel / distanceTraveled);
}

double estimatedRange(const double & remainingFuel,
                      const double & consumedFuel)
{
   return estimatedRange(remainingFuel,consumedFuel, 100.0);
}
