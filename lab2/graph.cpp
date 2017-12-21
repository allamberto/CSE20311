//Ana Luisa Lamberto
//CSE Lab - Lab 2
//Purpose: generates a simple ASCII Art graph of a mathematical function

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
   {
   // set variable length to 2 decimals
   cout << fixed << setprecision(2);

   cout << "The function is y = 8(cos(2x) + 1.5) from x = 0.00 to x = 12.00" << endl;
   cout << endl;
   cout << '\t' << "X" << '\t' << "Y" << '\t' << endl;

   float X, Y;
   float minY = 12;
   float minX = 12;
   float maxY = 0;
   float maxX = 0;
   for(X = 0; X <= 12; X = X + .2)
      {
      Y = 8*(cos(2*X) + 1);
      cout << '\t' << X << '\t' << Y << '\t';
      for (int counter = 0; counter <= Y; ++counter)
          {
          cout << "#";
          }
      if(Y > maxY)
          {
          maxY = Y;
          maxX = X;
          }
      else if (Y < minY)
          {
          minY = Y;
          minX = X;
          }
      cout << endl;
      }

   cout << "One maximum of the function 8(cos(2X)+1) on the domain (0 <= X <=12) is " << maxY << " at x = " << maxX << "." <<  endl;
   cout << "A minimum of the function is " << minY << " at x = " << minX <<  "." <<  endl;

   return 0;
   }
