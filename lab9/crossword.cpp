//Ana Lamberto
//main code for crossword puzzle - crossword.cpp

#include "board.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char*argv[]){
        Board b;
        ifstream ifs;
        ofstream ofs;
        string file, word;
        int count = 0;

        switch(argc){
                case 1: //interactive mode
                        cout << "Please enter your words(up to 20 with a maximum of 15 letters per word), followed by a period:\n ";
                        cin >> word;
                        while(word != "."){ //take in input
                                b.setWord(word);
                                cin >> word;
                                count++;
                        }
                        b.setSize(count); //set size of input
                        b.sortWordList();
                        b.placeFirst(b.getWord(0)); //place longest word in vector in center of board
                        for(int i = 1; i < b.getSize(); i++){ //for all words
                                if((b.placeWord(b.getWord(i))) == false){ //if word can be placed, tell user
                                        cout << "\n" << b.getWord(i) << " could not be placed. It was skipped." << endl;
                                }
                        }
                        b.printPuzzle(cout);
                        b.updateSol(); //update solution
                        b.printSolution(cout);
                        b.clues(cout);
                        break;

                case 2://file input, standard output
                        file = argv[1]; //save file name from command line
                        ifs.open(file);
                        if(!ifs){ //double check file validity
                                cout << "Invalid File Name - Please enter valid name: ";
                                cin >> file;
                                ifs.open(file);
                        }
                        while(ifs.peek() != EOF){ //gather input data from filereak;
                                getline(ifs, word, '\n');
                                b.setWord(word);
                                count++;
                        }
                        b.setSize(count); //set size of input
                        b.sortWordList();
                        b.placeFirst(b.getWord(0)); //place longest word in vector in center of board
                        for(int i = 1; i < b.getSize(); i++){
                                if((b.placeWord(b.getWord(i))) == false)
                                        cout << "\n" << b.getWord(i) << " could not be placed. It was skipped." << endl;
                        }
                        b.printPuzzle(cout);
                        b.updateSol();
                        b.printSolution(cout);
                        b.clues(cout);
                        break;
                case 3: //file input, file output
                        file = argv[1]; //save file name from command line
                        ifs.open(file);
                        if(!ifs){ //double check file validity
                                cout << "Invalid File Name - Please enter valid name: ";
                                cin >> file;
                                ifs.open(file);
                        }
                        while(ifs.peek() != EOF){ //gather input data from filereak;
                                getline(ifs, word, '\n');
                                b.setWord(word);
                                count++;
                        }
                        file = argv[2]; //file from command line
                        ofs.open(file);
                        if(!ofs){ //check input
                                cout << "Invalid File Name - Please enter valid name: " << file << endl;
                                cin >> file;
                                ofs.open(file);
                        }
                        b.setSize(count);
                        b.sortWordList();
                        b.placeFirst(b.getWord(0));
                        for(int i = 1; i < b.getSize(); i++){
                                if((b.placeWord(b.getWord(i))) == false)
                                        ofs << "\n" << b.getWord(i) << " could not be placed. It was skipped." << endl;
                        }
                        b.updateSol();
                        b.printPuzzle(ofs); //pass ofs in order to print to new file
                        b.printSolution(ofs);
                        b.clues(ofs);
                        break;

                default: //catch invalid input at command line
                        cout << "Error - Please enter valid arguments at the command line" << endl;
                        break;

        }

        return 0;
}

