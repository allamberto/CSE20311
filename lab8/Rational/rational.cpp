// Ana Lamberto
// Purpose: implementation for the Rational class
#include "rational.h"
#include <iostream>
#include <cmath>
using namespace std;

Rational::Rational() //default constructor
{
        numer = 1;
        denom = 1;
}

Rational::Rational(int n, int d) //constructor
{
        numer = n;
        denom = d;
}

void Rational::setRational(int n, int d)
{
  setNumer(n);
  setDenom(d);
}

Rational::~Rational() //deconstructor
{ }

int Rational::getNumer()
{
        return numer;
}

int Rational::getDenom()
{
        return denom;
}

void Rational::setNumer(int n)
{
        numer = n;
}

void Rational::setDenom(int d)
{
        denom = d;
}

void Rational::print()
{
        Rational s(numer, denom);
        s = check(s);
        s = simplify(s);
        if (denom == 0)
        cout << "Error - can't divide by 0" << endl;
        else
                cout << s.getNumer() << "/" << s.getDenom() << endl;
}

Rational Rational::operator+(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();

        if(d2 == denom){ //if they have the same denominator, add immediately
                s.setNumer(numer + n2);
                s.setDenom(d2);
        }

        else{ // multiple numerators by denominators to get common denominator
                s.setNumer((d2*numer) + (denom*n2));
                s.setDenom(denom * d2);
        }
        s = simplify(s); //simplify rational
        s = check(s); //fix negatives
        return s;
}


Rational Rational::operator-(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();

        if(d2 == denom){ //if they have the same denominator, subtract immediately
                s.setNumer(numer - n2);
                s.setDenom(d2);
        }

        else{ //multiple numerators by denominators to get common denominator
                s.setNumer((denom*d2) - (d2*numer));
                s.setDenom(denom*d2);
        }
        s = simplify(s);
        s = check(s);
return s;
}

Rational Rational::operator*(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();

        s.setNumer(numer*n2); //multiple numerator by numerator
        s.setDenom(denom*d2);// multiple denom by denom
        s = simplify(s);
        s = check(s);
        return s;
}

Rational Rational::operator/(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();

        s.setNumer(numer*d2); //multiply by reciprocal
        s.setDenom(denom*n2);
        s = simplify(s);
        s = check(s);
        return s;
}




Rational Rational::simplify(Rational x){
        int gcf = 1;
        Rational s; //new rational to be returned

        for(int i = 1; i <= abs(x.getNumer()) && i <= abs(x.getDenom()); i++){ //simplify by finding greatest common factor between both nums
                if((x.getNumer() % i == 0) && (x.getDenom() % i == 0)){ //if both remainders are 0 then i is a factor
                        gcf = i;
                }
        }

        s.setNumer(x.getNumer()/gcf); //divide by greatest factor for simplifed form
        s.setDenom(x.getDenom()/gcf);
        return s;
}

Rational Rational::check(Rational x){
        Rational s;
        if ((x.getNumer() < 0) && (x.getDenom() < 0)){
                s.setNumer(-(x.getNumer())); //change numer to positive
                s.setDenom(-(x.getDenom())); //change denom to positive
}
        else if(x.getDenom() < 0){
                s.setNumer(-(x.getNumer())); //put negative sign in front of numerator instead of denominator
                s.setDenom(-(x.getDenom())); //set Denom positive

        }
        else{
                s.setNumer(x.getNumer()); //if neither, keep same Rational
                s.setDenom(x.getDenom());
        }

        return s;
}


ostream& operator<< (ostream &s, Rational &r){ //overloading the output operator
        if (r.getDenom() == 0)
                s << "Error - Can't divide by zero" << endl;
        else
                s << r.getNumer() << "/" << r.getDenom();
        return s;
}

// overloaded the input operator
istream& operator>> (istream &s, Rational &r){
        int x, y;

        cout << "Enter the numerator and denominator: ";
        s >> x >> y;
        r.setRational(x, y);
        return s;
}
