//Ana Lamberto
//Purpose: main code -  statemain.cpp - for State class
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include "state.h"
using namespace std;

void menu();
void displayAll(vector<State>);
string lower(string);

int main(){
        ifstream ifs;
        string file;
        string abrev, name, cap, popS, yrS, numRepS; //string inputs
        int pop, yr, numRep; //ints for class
        vector<State> states;
        State st;
        bool doExit = 0; //for switch case
        string ss; //for switch case
        int choice; //for switch case

        cout << "enter data file name: ";
        cin >> file;
        ifs.open(file);
        while (!ifs) { //invalid ifs, take in new input
                cout << "-Invalid File Name-" << endl;
                cout << "Enter data file name: ";
                cin >> file;
                ifs.open(file);
        }

        while(ifs.peek() != EOF) { //taking input from cvs
                getline(ifs, abrev, ',');
                getline(ifs, name, ',');
                getline(ifs, cap, ',');
                getline(ifs, popS, ',');
                getline(ifs, yrS, ',');
                getline(ifs, numRepS, '\n');
                //take certain string inputs and turn into ints
                pop = stoi(popS);
                yr = stoi(yrS);
                numRep = stoi(numRepS);
                st = State(abrev, name, cap, pop, yr, numRep); //pass values to class
                states.push_back(st); //add state to vector
        }
        while(!doExit){
                menu();
                cout << "Your choice: ";
                cin >> choice;
                switch(choice){
                        case 1:
                                displayAll(states);
                                break;

                        case 2:
                                cout << "Which state would you like info for: ";
                                cin >> ss;
                                ss = lower(ss); //convert all letters to lowercase for comparison purposes
                                for (auto it = states.begin(); it < states.end(); it++){ //loop through states and check names
                                        if (lower((*it).getName()) == ss){
                                                cout << (*it).getAbrev() << '\t' << (*it).getName() << '\t' << (*it).getCap() << '\t' << (*it).getPopulation() << '\t' << (*it).getYear() << '\t' << (*it).getNumRep() << '\t' << endl;
                                        }
                                }
                                break;

                        case 3:
                                cout << "Which state would you like info for: ";
                                cin >> ss;
                                ss = lower(ss); //convert all letters to lowercase for comparison purposes
                                for (auto it = states.begin(); it < states.end(); it++){ //loop through states
                                        if (lower((*it).getName()) == ss){
                                                cout << "Abbreviation for " << (*it).getName() << ": " << (*it).getAbrev() << endl;
                                        }
                                }
                                break;

                        case 4:
                                int yr;
                                cout << "What year would you like to search for: ";
                                cin >> yr;
                                if ((yr < 1776) || (yr > 2017)){ //check for invalid input
                                        cout << "Invalid year. Please try again." << endl;
                                        cout << "What year would you like to search for: ";
                                        cin >> yr;
                                }

                                cout << "States founded in " << yr << ": " << endl;
                                for (auto it = states.begin(); it < states.end(); it++){ //loop through states
                                        if ((*it).getYear() == yr){
                                                cout << (*it).getName() << endl;
                                        }
                                }
                                break;

                        case 5:
                                doExit = true;
                                break;
                        default:
                                cout << "\nError - Please pick a valid option." << endl;
                }
        }

        return 0;

}

void menu(){ //menu options
        cout << "What would you like to do?" << endl;
        cout << "\t1) Display info on all the states.\n\t2) Display info on a specific state.\n\t3) Find abbreviation for a certain state.\n\t4) Find all states founded in a certain year.\n\t5) Quit" << endl;
}

void displayAll(vector<State> s){ //display all states
        cout << setw(20) << "Abbreviation" << setw(20) << "State Name" << setw(20) << "Capital" << setw(20) << "Population" <<  setw(20) << "Founding Year" << setw(30) << "# of Reps in Congress" << endl;
        for(auto it = s.begin(); it < s.end(); ++it){
                cout << setw(20) << (*it).getAbrev() << setw(20) << (*it).getName() << setw(20) << (*it).getCap() << setw(20) << (*it).getPopulation() << setw(20) << (*it).getYear() << setw(20) << (*it).getNumRep() << endl;
        }
}

string lower(string ss){ //turns entire string to lowercase
        for(int i = 0; i < ss.length(); ++i){
          ss[i] = tolower(ss[i]);
        }
        return ss;
}
