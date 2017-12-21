//Ana Lamberto
//Purpose: Life Class implementation - lifeboard.cpp

#include "lifeboard.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Life::Life(){ //constructor
        row = 40;
        column = 40;
        for(int r = 0; r < row; r++){ //turn every cell to dead
                for(int c = 0; c < column; c++){
                        board[r][c] = ' ';
                }
        }
}

void Life::set(int i, int j, char x){ //access private board variables
        board[i][j] = x;
}

void Life::reset(){ //set all cells to dead
        for(int r = 0; r < row; r++){
                for(int c = 0; c < column; c++){
                        board[r][c] = ' '; //turn every value to blank  
                }
        }
}

void Life::print(){ //print board
        system("clear");
        for(int r = -1; r <= row; r++){ //add extra row at beginning and end to print border
                for(int c = -1; c <= column; c++){//add extra column at beginning and end to print border
                        if((r == -1) || (r == row))
                                cout << '-';
                        else if((c == -1) || (c == column))
                                cout << "|";
                        else
                                cout << board[r][c]; //print board inside border
                }
        cout << endl;
        }

}

void Life::advance(){
        int live = 0;
        Life tempBoard;

        for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){ //loop through entire matrix
                        live = 0; //reset live
                        for(int m = i - 1; m < i + 2; m++){ //loop through smaller 3x3 matrix
                                for(int n = j - 1; n < j + 2; n++){
                                        if((m != i) || (n != j)){ //if not checking current cell block
                                                if((m >= 0) && (m < 40) && (n >= 0) && (n < 40)){ //if m and n are in the overall matrix
                                                        if(board[m][n] == 'X'){ //and if cell is alive
                                                                live++; //add life to counter
                                                        }
                                                }
                                        }
                                }
                        }
                // once you know how much life is in the small matrix
                if(live == 3) //check to see if should turn from dead to alive
                        tempBoard.board[i][j] = 'X';
                else if((live < 2) || (live > 3)) //check to see if should turn from alive to dead
                        tempBoard.board[i][j] = ' ';
                else //else copy board
                        tempBoard.board[i][j] = board[i][j];
                }
        }
        tempBoard.upload(*this); //upload temporary board to real board

}

void Life::upload(Life &newBoard){ //loop through temp board and add all values to new Board
        for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                        newBoard.board[i][j] = board[i][j];
                }
        }
}
