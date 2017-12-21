#include <iostream>
using namespace std;

int main()
{
   int TD = 6;
   int numTD;
   cout << "How many touchdowns were scored during the game: ";
   cin >> numTD;

   int extra = 1;
   int numExtra;
   cout << "How many extra points were scored during the game: ";
   cin >> numExtra;

   int FG = 3;
   int numFG;
   cout << "How many field goals were scored during the game: ";
   cin >> numFG;

   int safeties = 2;
   int numSafeties;
   cout << "How many safeties were scored during the game: ";
   cin >> numSafeties;

   int totPoints = TD*numTD + extra*numExtra + FG*numFG + safeties*numSafeties;
   cout << "The total number of points scored by the Irish was " << totPoints
   <<"." << endl;

   return 0;
}
                            
