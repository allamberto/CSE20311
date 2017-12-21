//Ana Luisa Lamberto
//CSE Lab - Lab 3
//Purpose: asks the user to enter two integer numbers and finds and displays the greatest common divisor between them.
#include <iostream>
using namespace std;

//declaring function
int getgcd(int, int);

int main()
{
int a, b, gcd;
cout << "Please enter two integers: ";
cin >> a >> b;
cout << endl;

gcd = getgcd(a,b); // using the function with given inputs
cout << "The greatest common demoniator between " << a << " and " << b << " is " << gcd << "." << endl;

return 0;
}

//defining function
int getgcd(int x, int y)
{
int gcd;
// loop as long as the counter is less than both integers
for(int counter = 1;((counter <= x) && (counter <= y)); counter++)
   {
   //if the remainder between both and integers and the counter is 0 then this is a common denominator
   if((x % counter == 0) && (y % counter == 0))
      {
      gcd = counter;
      }
   }
return gcd;
}
