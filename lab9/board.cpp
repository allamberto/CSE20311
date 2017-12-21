//Ana Lamberto
//Purpose: implementation for board class - board.cpp

#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

Board::Board(){ //constructor
        for(int r = 0; r < 15; r++){
                for(int c = 0; c < 15; c++){
                        crossword[r][c] = '.'; //fill puzzle board with periods
                        solution[r][c] = '#'; //fill solution board with hashtags
                }
        }
}

void Board::printPuzzle(ostream& s){ //pass ostream to control type of output
        for(int r = 0; r < 15; r++){
                for(int c = 0; c < 15; c++){
                        s << crossword[r][c];
                }
        s << endl;
        }
}

void Board::printSolution(ostream& s){ //pass ostream to control type of output
        for(int r = 0; r < 15; r++){
                for(int c = 0; c < 15; c++){
                        s << solution[r][c];
                }
        s << endl;
        }
}


void Board::setWord(string w){
        for(int i = 0; i < w.length(); i++){ //change all letters to upper case
                w[i] = toupper(w[i]);
        }
        wordList.push_back(w);
}

void Board::wordRemove(int i){ //remove word in word list
        wordList.erase(wordList.begin() + i);
}

void Board::setSize(int i){
        size = i;
}
int Board::getSize(){
        return size;
}

string Board::getWord(int index){ //return word in the word lsit
        return wordList[index];
}

void Board::getWordList(){ //print wordlist
        for(auto it = wordList.begin(); it < wordList.end(); it++){
                cout << *it << endl;
        }
}

void Board::updateSol(){
        for(int r = 0; r < 15; r++){
                for(int c = 0; c < 15; c++){
                        if(isalpha(crossword[r][c])) //change all letters to blank spaces
                                solution[r][c] = ' '; //update solution
                }
        }
}

void Board::placeFirst(string w){
        int center = floor((15 - w.length())/2); //calculate how many spaces should be left on either side for word to be centered
        for(int i = 0; i < w.length(); i++){
                crossword[7][center + i] = w[i];
        }
        places.push_back(7); //row position of beginning of word
        places.push_back(center); //col position of beginning of word
        placed.push_back(true); //word was placed
        positions.push_back("Across"); //it goes across
}

void Board::sortWordList(){ //bubble sort to sort words in greatest length
        int i, j;
        for (i = 0; i < wordList.size() - 1; i++){
                for (j = 0; j < wordList.size()-i-1; j++){
                        if(wordList[j].length() < wordList[j+1].length()){
                                string temp = wordList[j]; //swap words
                                wordList[j] = wordList[j+1];
                                wordList[j+1] = temp;
                        }
                }
        }
}

bool Board::shareLetter(char a, string b){
        for(int i = 0; i < b.length(); i++){
                if(b[i] == a)
                        return true;
        }
return false;
}

bool Board::placeHor(char a, int x, int y, string s){ //horizontal - check if word can fit
        int place = s.find(a); //where intersection letter falls in word

        int count = 0;
        for(int i = 0; i < s.length(); i++){
                if(i < place){ //before intersection point
                        if(((y - i - 1) >= 0) && ((x - 1) >= 0) && ((x + 1) < 15)){ //in matrix
                                if(ispunct(crossword[x + 1][y - i - 1]) && ispunct(crossword[x][y - i - 1]) && ispunct(crossword[x - 1][y - i - 1]) && (ispunct(crossword[x][y - 1])))
                                        count++; //if surrounding rows and cols are periods then add to count
                        }
                }
                else if(i > place){ //after intersection point
                        if(((y + i + 1) < 15) && ((x - 1) >= 0) && ((x + 1) < 15)){ //if in matrix
                                if(ispunct(crossword[x + 1][y + i + 1]) && ispunct(crossword[x][y + i + 1]) && ispunct(crossword[x - 1][y + i + 1]) && (ispunct(crossword[x][y - 1])))
                                        count++;
                        }

                }
        }
        if(count == s.length() - 1){ //if every letter had the correct number of spaces around it, place word
                return true;
        }
        else
                return false;
}

bool Board::placeVer(char a, int x, int y, string s){ //vertical - check if word can fit
        int place = s.find(a); //where intersection letter falls in word

        int count = 0;
        for(int i = 0; i < s.length(); i++){

                if(i < place){ //before intersection point
                        if(((y + 1) < 15) && ((y - 1) >= 0) && ((x - i - 1) >= 0)){ //in matrix
                                if(ispunct(crossword[x - i - 1][y - 1]) && ispunct(crossword[x - i - 1][y]) && ispunct(crossword[x - i - 1][y + 1]) && (ispunct(crossword[x - 1][y])))
                                        count++; //if surrounding rows and cols are periods then add to count
                        }
                }
                else if(i > place){ //after intersection
                if(((y + 1) < 15) && ((y - 1) >= 0) && ((x + i + 1) < 15)){ //if in matrix
                                if(ispunct(crossword[x + i + 1][y + 1]) && ispunct(crossword[x + i + 1][y]) && ispunct(crossword[x + i + 1][y - 1]) && (ispunct(crossword[x - 1][y])))
                                        count++; //if surrounding rows and cols are periods then add to count
                        }

                }
        }
        if(count == s.length() - 1){ //if every letter had the correct number of spaces around it, place word
                return true;
        }
        else{
                return false;
        }
}

bool Board::placeWord(string word){ //combines all methods to actually place words if applicable
        bool Placed = false;
        for(int r = 0; r < 15; r++){
                for(int c = 0; c < 15; c++){
                        if(shareLetter(crossword[r][c], word)){ //if the space holds a char that is in the word
                                if(placeHor(crossword[r][c], r, c, word)){ //if the word fits horizontally
                                        horizontal(crossword[r][c], r, c, word); //place this word horizontally
                                        Placed = true; //mark as placed
                                }
                                else if(placeVer(crossword[r][c], r, c, word)){ //if its fits vertically
                                        vertical(crossword[r][c], r, c, word); //place word vertically
                                        Placed = true; //mark as placed
                                }
                        }
                if(Placed)
                        break;
                }
        }
        if(Placed == false) //if can't be placed, mark as so
                placed.push_back(false);
        return Placed;
}

void Board::horizontal(char a, int r, int c, string word){ //places word horizontally
        int place = word.find(a);
        for(int i = 0; i < word.length(); i++){
                if(i < place){ //before intersection
                        crossword[r][c - (place - i)] = word[i];
                }
else if(i > place){ //after intersection
                        crossword[r][c + (i - place)] = word[i];
                }
        }
        places.push_back(r); //save row where word starts
        places.push_back(c - place); //save col where word starts 
        placed.push_back(true); //mark as placed
        positions.push_back("Across"); //mark as placed horizontally
}

void Board::vertical(char a, int r, int c, string word){ //places word vertically
        int place = word.find(a);
        for(int i = 0; i < word.length(); i++){
                if(i < place){ //before intersection
                        crossword[r - (place - i)][c] = word[i]; //work way towards center of word
                }
                else if(i > place){ //after intersection
                        crossword[r + (i - place)][c] = word[i]; //work away from the center of the word
                }
        }
        places.push_back(r - place); //save row where word starts
        places.push_back(c); //save col where word starts
        placed.push_back(true); //mark as placed
        positions.push_back("Down"); //mark as placed vertically
}


void Board::clues(ostream& s){ //pass ostream to control output
        s << "Clues:\n" << endl;
        int n = 0;
        int m = 0;
        for(auto it = wordList.begin(); it < wordList.end(); it++){ //for all words
                if(placed[m] == true){ //if that word was used
                        int x = places[n]; //take row from saved values in vector
                        int y = places[n + 1]; //take col from saved values in vector
                        s << x << ", " << y << " ";
                        s << positions[m] << " "; //take orientation from saved values in vector
                        string w = scramble(*it); //scramble word
                        s << w << endl;
                        n = n + 2; //increment by 2 to next coordinate
                }
                m++; //increment placed value vector every time not just when true
        }
}

string Board::scramble(string w){
        random_shuffle(w.begin(), w.end());
        return w;
}
