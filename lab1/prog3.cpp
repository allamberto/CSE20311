#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   cout << "Welcome to the Cross Product Calculator!" << endl;

   int u1;
   int u2;
   int u3;
   cout << "Please enter three integers for your first vector: ";
   cin >> u1 >> u2 >> u3;
   if (cin.fail())
      {
      cout << "The input must be a number.";
      return 0;
      }

   int v1;
   int v2;
   int v3;
   cout << "Please enter three integers for your second vector: ";
   cin >> v1 >> v2 >> v3;
   if (cin.fail())
     {
     cout << "The input must be a number.";
     return 0;
     }

   int w1;
   int w2;
   int w3;

   w1 = u2*v3 - u3*v2;
   w2 = u1*v3 - u3*v1;
   w3 = u1*v2 - u2*v1;

   cout << "Your resulting vector is " << w1 << "i - " << w2 << "j + " << w3 << "k." << endl;

   double mag = sqrt(pow(w1,2) + pow(w2, 2) + pow(w3, 2));
   cout << "The magnitude of your resulting vector is " << mag << ".";

   return 0;

}
