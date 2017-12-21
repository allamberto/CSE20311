//Ana Lambertp
//Purpose: main code for Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(2,3), c, s;

  cout << "*** display a ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "Sum of a and b: ";
  s = a.add(b);
  s.print();

  // 'mathematically subtract a and b
  cout << "Difference of a and b: ";
  s = a.subtract(b);
  s.print();

  // 'mathematically multiply a and b
  cout << "Product of a and b: ";
  s = a.multiply(b);
  s.print();

  // 'mathematically divide a and b
  cout << "Quotient of a and b: ";
  s = a.divide(b);
  s.print();


  return 0;
}
