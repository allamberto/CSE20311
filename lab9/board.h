//Ana Lamberto
//Purpose: interface for board class - board.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board{
        public:
                Board(); //constructor

                // access methods
                void setWord(string);
                string getWord(int);
                void setSize(int);
                int getSize();
                void wordRemove(int);

                //utilties
                void printPuzzle(ostream&);
                void printSolution(ostream&);
                void getWordList();
                void updateSol();
                void placeFirst(string);
                void sortWordList();
                bool placeWord(string);
                void clues(ostream&);
                bool shareLetter(char a, string b);
                bool placeVer(char, int, int, string);
                bool placeHor(char, int, int, string);
                void horizontal(char, int, int, string);
                void vertical(char, int, int, string);
                string scramble(string);
        private:
                char crossword[15][15];
                char solution[15][15];
                vector<string> wordList;
                vector<int> places;
                vector<bool> placed;
                vector<string> positions;
                int size;
};
