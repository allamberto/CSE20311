//Ana Luisa Lamberto
//Lab 3
//Purpose: The program will act as a text menu driven basic calculator for the four simple arithmetic operations: add, subtract, multiply, divide.

#include <iostream>
#include <cmath>
using namespace std;

//declare functions
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

int main()
{
int choice = 0;
float x, y, result;

while(choice != 5){ //loop until exit value is entered
   cout << "What would you like to do?" << endl;
   cout << '\t' << "1 for additon" << endl;
   cout << '\t' << "2 for subtraction" << endl;
   cout << '\t' << "3 for multiplcation" << endl;
   cout << '\t' << "4 for division" << endl;
   cout << "\t" << "5 to exit" << endl;

   cout << "What's your choice: ";
   cin >> choice; //input user choice
   cout << endl;

   //insert if statement so program doesn't ask for values when choice = 5 or invalid
   if((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4)){
      cout << "What are your two numbers: ";
      cin >> x >> y; //input two numbers
      cout << endl;
      }

   //check not to divide by zero
   while((y == 0) && (choice == 4))
      {
      cout << "Sorry you can't divide by zero. Try a different value." << endl;
      cout << "What are your two numbers: ";
      cin >> x >> y; //input two numbers
      }

   //directs choice to proper function
   if(choice == 1)
      {
      result = add(x,y);
      cout << "The sum of " << x << " and " << y << " is " << result << "." << endl;
      }
   else if(choice == 2)
      {
      result = subtract(x,y);
      cout << "The difference of " << x << " and " << y << " is " << result << "." << endl;
      }
   else if(choice == 3)
      {
      result = multiply(x,y);
      cout << "The product of " << x << " and " << y << " is " << result << "." << endl;
      }
   else if(choice == 4)
      {
      result = divide(x,y);
      cout << "The quoteint of " << x << " and " << y << " is " << result << "." << endl;
      }
   else if(choice == 5)
      {
      cout << "Thanks for using the calculator!";
      }
   else
      {
      cout << "This is an invalid entry. Try again." << endl;
      }
   }

return 0;
}
 //adds to values
float add(float a, float b){
float c = a + b;
return c;
}
// subtracts two values
float subtract(float a, float b)
{
float c = a - b;
return c;
}
//multiplies two values
float multiply(float a, float b)
{
float c = a * b;
return c;
}
//checks to make sure doesn't divide by zero, then divides two numbers
float divide(float a, float b)
{
float c = a/b;
return c;
}

      
