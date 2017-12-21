//Ana Lamberto
//main code for Rational class - rationalmain.cpp

#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a, b, c(), s;
  cin >> a; //overloaded cins
  cin >> b;

  cout << "\na: " << a << "\nb: " << b << endl; //overloaded couts
  cout << "c: " << c << endl;

  // 'mathematically' add a and b
  s = a + b;
  cout << "\nSum of a and b: " << s << endl;

  // 'mathematically subtract a and b
  s = a - b;
  cout << "Difference of a and b: " << s << endl;

  // 'mathematically multiply a and b
  s = a * b;
  cout << "Product of a and b: " << s << endl;

  // 'mathematically divide a and b
  s = a/b;
  cout << "Quotient of a and b: " << s << endl;



  return 0;
}
