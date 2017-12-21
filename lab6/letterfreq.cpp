//Ana Luisa Lamberto
//Lab 6
//Purpose: Find the frequency of each letter in a text file.


#include <iostream>
#include <fstream>
#include <cctype>
#include <array>
#include <iomanip>
using namespace std;

void checkLetter(char, array<int, 26> &, int &, int &, int &);
void display(array<int, 26>, int, int, int);

int main(){

        //set variable length to 2 decimals
        cout << fixed << setprecision(1);

        array<int, 26> letterfreq = {0}; // array that holds frequency of letters
        int totLetter = 0;
        int totSpace = 0;
        int totChar = 0;
        char c; //character taken in
        ifstream ifs;
        string input; //get startup data file
        cout << "Please choose a \"startup\" data file: ";
        cin >> input;

        ifs.open(input);
        while(!ifs){ //check to make sure text file is valid
                cout << endl << "Error - Try again.\n" << endl;
                cout << "Please choose a \"startup\" data file: ";
                cin >> input;
                ifs.open(input); //reload new input if not valid
        }
        ifs.get(c); //take first character
        checkLetter(c, letterfreq, totLetter, totSpace, totChar);

        while(!ifs.eof()){
                c++;
                ifs.get(c); //take next character
                checkLetter(c, letterfreq, totLetter, totSpace, totChar);
        }
        display(letterfreq, totLetter, totSpace, totChar);
}

void checkLetter(char c, array<int, 26>& letterfreq, int& totLetter, int& totSpace, int& totChar){
                totChar++; //increment number of chars
                if (isalpha(c)){
                        char nc = tolower(c); //turn that character into lower case
                        letterfreq[nc-97]++;
                        totLetter++; //increment leter total
                }
                else if (isspace(c))
                        totSpace++; //increment space total

}

void display(array<int, 26> letterfreq, int totLetter, int totSpace, int totChar){
        char printChar = 97; //lower case a in ascii
        int count = 0; //number of columns
        for (int i: letterfreq){
                if (count < 5){
                        cout << printChar++ << ":" << setw(5) << i << setw(7);
                        count++; //keep track of columns
                }
                else{
                        cout << right << setw(5) << printChar++ << ": " << i << endl;
                        count = 0;
                }
        }

        cout << "\nThere were " << totLetter << " letters." << endl;
        cout << "There were " << totChar << " total characters." << endl;
        cout << "There were " << totSpace << " total white spaces." << endl;
        cout << "Space percentage: " << ((float)totSpace/totChar) * 100 << "%" << endl;
}

                        
