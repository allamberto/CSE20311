// Ana Lamberto
// Purpose: interface for Rational class - rational.h
#include <iostream>
using namespace std;

class Rational
{
    friend ostream& operator<< (ostream &, Rational &);
    friend istream& operator>> (istream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    void setRational(int, int);
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    Rational simplify(Rational);
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    Rational check(Rational);
  private:
    int numer;
    int denom;
};
