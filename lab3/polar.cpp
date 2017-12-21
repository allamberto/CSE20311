//Ana Luisa Lamberto
//CSE Lab - Lab 3
//Purpose: prompts the user for the x and y coordinates for a point in a Cartesian coordinate system and then finds and displays the point's corresponding polar coordinates and the quadrant that the point is in; or the axis it is on; or the origin, as the case may be.

#include <iostream>
#include <cmath>
const double PI = 3.14159;

using namespace std;

//declaring functions
double getPolRad(double, double);
double getPolAng(double, double);
int getQuad(double, double);
double correctPolAng(double, int);

int main()
{

double x, y, polRad, polAng, quad;

// input
cout << "Please provide two coordinates in a Cartesian coordinate system: ";
cin >> x >> y;
cout << endl;

//using functions
polRad = getPolRad(x,y);
polAng = getPolAng(x,y);
quad = getQuad(x,y);
//polAng = correctPolAng(polAng, quad);

cout << "The polar coordinates to these Cartesian coordinates are (" << polRad << ", " << polAng << ")." << endl;

//checking to see if original coordinates are on the origin or on an axis
if (x == 0)
{
   if (y == 0)
   {
   cout << "The coordinates are at the origin." << endl;
   }
   else if (y > 0)
   {
   cout << "The coordinates are on the postive y axis." << endl;
   }
   else if (y < 0)
   {
   cout << "The coordinates are on the negative y axis." << endl;
   }
}
if ((x != 0) && (y != 0)) //includes conditional so it won't print the quadrant if point is on the origin 
{
   cout << "The quadrant is : " << quad << "." << endl;
}  
return 0;
}

double getPolRad(double x, double y)
{
double polRad;
polRad = sqrt(pow(x,2) + pow(y,2));
return polRad;
}

double getPolAng(double x, double y)
{
double polAng;
polAng = atan2(y,x) * (180/PI);
return polAng;
}

int getQuad(double x, double y)
{
int quad;
//checks cartesian sign to figure out which quadrant the polAng will fall in
if((x > 0) && (y > 0))
   {
   quad = 1;
   }
else if((x < 0) && (y > 0))
   {
   quad = 2;
   }
else if((x < 0) && (y < 0))
   {
   quad = 3;
   }
else
   {
   quad = 4;
   }
return quad;
}

//puts the polar angle in the right quadrant for atan command
double correctPolAng(double polAng, int quad)
{
if((quad == 2) || (quad == 3))
   {
   polAng = polAng + 180;
   }
else if(quad == 4)
   {
   polAng = polAng + 360;
   }
return polAng;
}

