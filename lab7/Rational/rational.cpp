// Ana Lamberto
// rational.cpp
// Purpose: implementation for the Rational class
#include "rational.h"
#include <iostream>
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
        cout << numer << "/" << denom << endl;
}

Rational Rational::add(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();
        int gcf;
        if(d2 == denom){ //if they have the same denominator, add immediately
                s.setNumer(numer + n2);
                s.setDenom(d2);
        }

        else{ // multiple numerators by denominators to get common denominator
                s.setNumer((d2*numer) + (denom*n2));
                s.setDenom(denom * d2);
        }

        gcf = GCF(s.getNumer(), s.getDenom());

        s.setNumer(s.getNumer()/gcf); //divide by GCF for simplified numer
        s.setDenom(s.getDenom()/gcf); //divide by GCF for simplified denom
        return s;
}


Rational Rational::subtract(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();
        int gcf;

        if(d2 == denom){ //if they have the same denominator, subtract immediately
                s.setNumer(numer - n2);
                s.setDenom(d2);
        }

        else{ //multiple numerators by denominators to get common denominator
                s.setNumer((denom*d2) - (d2*numer));
                s.setDenom(denom*d2);
        }

        gcf = GCF(s.getNumer(), s.getDenom());
        s.setNumer(s.getNumer()/gcf); //divide by GCF for simplified numer
        s.setDenom(s.getDenom()/gcf); //divide by GCF for simplified denom
        return s;
}

Rational Rational::multiply(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();
        int gcf;

        s.setNumer(numer*n2);
        s.setDenom(denom*d2);
        gcf = GCF(s.getNumer(), s.getDenom());
        s.setNumer(s.getNumer()/gcf); //simplify
        s.setDenom(s.getDenom()/gcf); //simplify
        return s;
}

Rational Rational::divide(Rational x)
{
        Rational s;
        int n2 = x.getNumer();
        int d2 = x.getDenom();
        int gcf;

        s.setNumer(numer*d2);
        s.setDenom(denom*n2);
        gcf = GCF(s.getNumer(), s.getDenom());
        s.setNumer(s.getNumer()/gcf); //simplify
        s.setDenom(s.getDenom()/gcf); //simplify        
        return s;
}




int Rational::GCF(int num1, int num2){
        int gcf = 1;

        for(int i = 1; i <= num1 && i <= num2; i++){ //simplify by finding greatest common factor between both nums
                if((num1 % i == 0) && (num2 % i == 0)){
                        gcf = i;
                }
        }

        return gcf;
}
