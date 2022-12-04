#include "board.h"
#include "ship.h"
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void PrintBoard();

int main(){
    bool win = false;
    char play;
    int xPos, yPos;

    printf("Would you like to play a game of battleship? (y or n)");
    cin >> play;
    while(play == 'y' && !win){
        printf("Welcome to the game!\n Rules:\nAll entries should be lowercase one character long.\n");
        PrintBoard();
        printf("Please place your Carrier (5 spaces long). Enter row charater, colomn number, and orientation ");
        win = true; //exit case
    }

    return 0;
}

void PrintBoard(){
    vector<char> Board(100, 'O'); //temp board of all empty spaces !!!

    printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n");
    printf("============================================\n");
    for(int i = 0; i < 10; i++){
        printf("%c  |", 65+i); //
        for(int j = 0; j < 10; j++){
            printf(" %c |", Board[10*i+j]);
            /*
            Here we will print our board map/vector
             - are we printing both sets of ships of just players?
            */
        }
        printf("\n");
    }    
}