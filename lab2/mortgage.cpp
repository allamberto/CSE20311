//Ana Luisa Lamberto
//CSE Lab - Lab 2
//Purpose: creates amortization table using three user input values that shows every payment of mortgage until it's paid off

#include <iostream>
#include <iomanip>
using namespace std;

int main()
   {
   //set variable length to 2 decimals
   cout << fixed << setprecision(2);

   float principal, iRate, monthPay;
   cout << "What is your principal, interest rate percentage, and desired monthly payment: ";
   cin >> principal >> iRate >> monthPay;
   while ((principal < 0) || (iRate < 0) || (monthPay < 0))
      {
      cout << "Your inputs must be positive. Try again." << endl;
      cout << "What is your principal, interest rate percentage, and desired monthly payment: ";
      cin >> principal >> iRate >> monthPay;
      }
   while (monthPay < ((1.0/12)*(.01*iRate)*principal))
      {
      cout << "This monthly payment will result in your balance going up every month. Choose a new monthly payment: ";
      cin >> monthPay;
      }
   cout <<  endl;

   float balance = principal;
   int month = 1;
   float interest = 0;
   float totPay = 0;
   cout << "Month" << '\t' << "Payment" << '\t' << "Interest" << '\t' << "Balance" << '\t'<< endl;

   while (balance >= monthPay)
      {
      interest = (1.0/12)*(.01*iRate)*balance;
      balance = balance - monthPay + interest;
      totPay = totPay + monthPay;
      cout << month << '\t' << "$" << monthPay << '\t' << "$" << interest << '\t' << "$" << balance << endl;      ++month;
      }
   // final row to table
   cout << month << '\t' << "$" << balance << '\t' << "$" << ((1.0/12)*(.01*iRate)*balance) << '\t' << "$" << "0.00" << endl;

   int years = month/12;
   int remainMonths = month % 12;
   totPay = totPay + balance; //addition of final balance not in while loop
   cout << "You paid a total of $" << totPay << " over " << years << " years and " << remainMonths << " months." << endl;

   return 0;
   }

   
