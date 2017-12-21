//Ana Luisa Lamberto
//Lab 4
//Purpose: stores the wins and losses of the ND Football team since 1990 into arrays, and will then provide a user with a menu of questions on the data.

#include <iostream>
#include "nd_data.h"
#include <cmath>
using namespace std;

//declaring functions
int getWins(int, int);
int getLosses(int, int);
int findLosses(int ,int);
int findWins(int, int);
int bestRec(int);
int worstRec(int);

int main(){

int choice, year, numWins, numLosses, curYear = 2016, origin = 1900, size = (curYear - origin); //variables used throughout the program

//setting up menu options
cout << "Please choose an option: " << endl;
cout << "\t1: Display the record for a given year." << endl;
cout << "\t2: Display wins for a given year." << endl;
cout << "\t3: Display losses for a given year." << endl;
cout << "\t4: Display years with at least \"n\" loses." << endl;
cout << "\t5: Display years with at least \"n\" wins." << endl;
cout << "\t6: Display year with the best record." << endl;
cout << "\t7: Display year with the worst record." << endl;
cout << "\t8: Display records over a given range of \"n\" years." << endl;
cout << "\t9: Quit" << endl;

cout << "\nEnter your choice: ";
cin >> choice;

while (choice != 9){
        //switch case to run option 
        switch(choice){
                case 1: //check record in a year
                cout << "\nWhat year would you like to check the record for: ";
                cin >> year;
                //checks to make sure year is within range
                while ((year > curYear) || (year < origin)) {
                        cout << "Please enter a year between " << origin << " and " << curYear << ": ";
                        cout << "\nWhat year would you like to check the record for: ";
                        cin >> year;
                }
                numWins = getWins(year, origin);
                numLosses = getLosses(year, origin);
                cout << "Wins in " << year << ": " << numWins << endl;
                break;

                case 3:
                cout << "\nWhat year would you like to check the record for: ";
                cin >> year;
                //checks to make sure year is within range
                while ((year > curYear) || (year < origin)) {
                        cout << "Please enter a year between " << origin << " and " << curYear << ": ";
                        cout << "\nWhat year would you like to check the record for: ";
                        cin >> year;
                }
                numLosses = getLosses(year, origin);
                cout << "Losses in " << year << ": " << numLosses << endl;
                break;

                case 4:
                cout << "\nAt least how many losses: ";
                cin >> numLosses;
                cout << "These years had " << numLosses << " losses: ";
                //loop through entire array to find losses
                for (int i = 0; i <= size; i++){
                        if (findLosses(numLosses, i) < 0){ //if return is less than 0 then the loss was less than input so skip this year
                                continue;
                        }
                        else {
                                year = findLosses(numLosses, i) + origin; //add 1900 to index to get year
                        }       cout << year << " ";
                }
                cout << endl;
                break;

                case 5:
                cout << "\nAt least how many wins: ";
                cin >> numWins;
                cout << "These years had " << numWins << " wins: ";
                //loop through entire array to find wins
                for (int i = 0; i <= size; i++){
                        if (findWins(numWins, i) < 0){ //if return is less than 0 then the win was less than input so skip this year
                                continue;
                        }
                        else {
                                year = findWins(numWins, i) + origin; //add 1900 to index to get year
                        }       cout << year << " ";
                }
                cout << endl;
                break;
                case 6:
                cout << "\nThe most recent year with the best record was " << (bestRec(size) + origin) << "." << endl;
                break;

                case 7:
                cout << "\nThe most recent year with the worst record was " << (worstRec(size) + origin) << "." << endl;
                break;

                case 8:
                int startYear, endYear; //bounds
                cout << "\nWhat year would you like to start with and what year would you like to end with: ";
                cin >> startYear >> endYear;
                cout << endl;
                //check that years are in range
                while ((startYear > curYear) || (startYear < origin) || (endYear > curYear) || (endYear < origin)) {
                        cout << "\nPlease enter valid years between " << origin << " and " << curYear << ": ";
                        cout << "What year would you like to start with and what year would you like to end with: ";
                        cin >> startYear >> endYear;
                        cout << endl;
                }
                cout << "\nYear\tWins\tLosses" << endl;
                //loop through these years and display records
                for (int i = startYear; i <= endYear; i++){ //only loop through designated years
                        cout << i << "\t" << getWins(i, origin) << "\t" << getLosses(i, origin) << endl;
                }
                break;

                default:
                cout << "\n---------------------------------" << endl;
                cout << "Please enter a valid input." << endl;
                cout << "---------------------------------" << endl;

        }
        //setting up menu options
        cout << "\nPlease choose an option: " << endl;
        cout << "\t1: Display the record for a given year." << endl;
        cout << "\t2: Display wins for a given year." << endl;
        cout << "\t3: Display losses for a given year." << endl;
        cout << "\t4: Display years with at least \"n\" losses." << endl;
        cout << "\t5: Display years with at least \"n\" wins." << endl;
        cout << "\t6: Display year with the best record." << endl;
        cout << "\t7: Display year with the worst record." << endl;
        cout << "\t8: Display records over a given range of \"n\" years." << endl;
        cout << "\t9: Quit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
}

return 0;
}

//defining functions

//gets wins in input year
int getWins(int year, int origin){
        int numWins = wins[(year - origin)]; //year minus 1900 equals position in array
        return numWins;
}

//gets losses in input year
int getLosses(int year, int origin){
        int numLosses = losses[(year - origin)]; //year minus 1900 equals position in array
        return numLosses;
}

//finds a year where an input number of losses was reached
int findLosses(int numLosses, int index){ //designed for loop in main program so functon starts at index in that loop
        if (losses[index] >= numLosses)
                return index; //returns position if the losses of that year are great than specified number
        else
                return -1;  //if losses aren't high enough, return -1
}

//finds a year where an input number of wins was reached
int findWins(int numWins, int index){ //designed for loop in main program so functon starts at index in that loop
        if (wins[index] >= numWins)
                return index; //returns position if the losses of that year are great than specified number
        else
                return -1;  //if losses aren't high enough, return -1
//finds best record in all years
int bestRec(int size){
        int maxYear; //year with best record
        float ratio = 1.0; //ratio of wins to losses
        for (int i = 0; i <= size; i++){
                if (((losses[i] * 1.0)/wins[i]) <= ratio){ //if ratio is smaller than curretn ratio, that means the record is better that year so make that year the max
                        //multiplied by 1.0 to get a float value
                        maxYear = i;
                        ratio = (losses[i] * 1.0)/wins[i];
                }
        }
        return maxYear;
}

//finds worst record in all years
int worstRec(int size){
        int minYear; //year with best record
        float ratio = 1.0; //ratio of wins to losses
        for (int i = 0; i <= size; i++){
                if (((wins[i] * 1.0)/losses[i]) <= ratio){ //if ratio is smaller than curretn ratio, that means the record is worse that year so make that year the max
                 //multiplied by 1.0 to get a float value
                        minYear = i;
                        ratio = (wins[i] * 1.0)/losses[i];
                 }
        }
        return minYear;
}

                


