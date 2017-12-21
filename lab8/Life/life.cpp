//Ana Lamberto
//Purpose: Main Life Game code - life.cpp

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include "lifeboard.h"
using namespace std;

void menu(); //interactive mode options

int main(int argc, char *argv[]){
        Life realBoard;
        ifstream ifs;
        string file, cond, x, y;
        char condition;
        int row, col;

        if(argc > 1){ //batch mode
                file = argv[1]; //save file name from command line
                ifs.open(file);
                if(!ifs){ //double check file validity
                        cout << "Invalid File Name - Please enter valid name: ";
                        cin >> file;
                        ifs.open(file);
                }
                while(ifs.peek() != EOF){ //gather input data from file
                        getline(ifs, cond, ' ');
                        getline(ifs, x, ' ');
                        getline(ifs, y, '\n');
                        condition = cond[0]; //string to char
                        row = stoi(x); //string to int
                        col = stoi(y); //string to int

                        switch(condition){
                                case 'a': //add cell
                                        realBoard.set(row, col, 'X');
                                        break;
                                case 'r': //remove cell
                                        realBoard.set(row, col, ' ');
                                        break;
                        }
                }
                realBoard.print();
                while(true){ //infinite loop of advancing board
                        realBoard.advance();
                        realBoard.print();
                        usleep(100000); //pause for one second
                }
        }

        else{ //interactive mode
                int x, y;
                bool doExit = 0;
                char choice;

                while(!doExit){
                        menu();
                        cin >> choice;
                        switch(choice){
                                case 'a': //add cell
                                        cout << "Enter the x and y coordinates you want to add: ";
                                        cin >> x >> y;
                                        if((x >= 40) || (x < 0) || (y >= 40) || (y < 0)){ //check for valid input
                                                cout << "Error - Try again" << endl;
                                                cout << "Enter the x and y coordinates you want to add: ";
                                                cin >> x >> y;
                                        }
                                        realBoard.set(x, y, 'X');
                                        realBoard.print();
                                        break;

                                case 'r': //remove cell
                                        cout << "Enter the x and y coordinates you want to remove: ";
                                        cin >> x >> y;
                                        if((x >= 40) || (x < 0) || (y >= 40) || (y < 0)){ //check for valid input
                                                cout << "Error - Try again" << endl;
                                                cout << "Enter the x and y coordinates you want to add: ";
                                                cin >> x >> y;
                                        }
                                        realBoard.set(x, y, ' ');
                                        realBoard.print();
                                        break;

                                case 'n': //advance board
                                        realBoard.advance();
                                        realBoard.print();
                                        break;

                                case 'q': //exit
                                        doExit = 1; //change flag
                                        break;

                                case 'p': //infinite loop of advancing
                                        while(true){
                                                realBoard.advance();
                                                realBoard.print();
                                                usleep(2000000);
                                        }
                                        break;
                                        
                                default:
                                        cout << "Error - Please Enter Valid Data" << endl;
                        }
                }
        }



        return 0;
}

void menu(){
        cout << "What would you like to do?" << endl;
        cout << "\ta: Enter coordinates for new live cell" << endl;
        cout << "\tr: Enter coordinates for cell to be removed" << endl;
        cout << "\tn: Advance system to next iteration" << endl;
        cout << "\tq: Quit program" << endl;
        cout << "\tp: Play the game continuously" << endl;
        cout << "Choice: ";
}
                                        
