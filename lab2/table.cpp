//Ana Luisa Lamberto
//CSE Lab - Lab 2
//Purpose: takes user input for size of multiplication table and then displays a  multiplication table exactly that big, with a top row header and a left column  header.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
   {
   int dimension1, dimension2;

   //Ask for user input for dimensions
   cout << "What would you like the dimensions of the multiplcation table to be: ";
   cin >> dimension1 >> dimension2;

   //first row
   cout << "*   ";
   for (int counter = 1; counter <= dimension1; ++counter)
      {
      cout << counter << "   ";
      }
   //start second row
   cout << endl;

   //insert remaining table by going through each column in a row then moving on to next row
   for (int counterA = 1; counterA <= dimension2; ++counterA)
      {
      for (int counterB = 1; counterB <= dimension1; ++counterB)
        {
        if (counterB == 1)  //if first number in row, then header
           {
           cout << counterA << "   " << (counterA * counterB) << "   ";
           }
        else if (counterB < dimension1) //middle numbers
           {
           cout << (counterA * counterB) << "   ";
           }
        else //final number in row so start new line
           {
           cout << (counterA * counterB) << endl;
           }
        }
      }

   return 0;
   }
