//#include "board.h"
//#include "ship.h"
#include "classFunctions.cpp"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintBoard();
void PlayerTurn(int);

int main(){
    bool win = false;
    char play;
    int xPos, yPos;
    string direction;

    Board playerBoard;
    Board opponentBoard;

    playerBoard.emptyBoard();
    opponentBoard.emptyBoard();

    printf("Would you like to play a game of battleship? (y or n)");
    cin >> play;
    while(play == 'y' && !win){
        printf("Welcome to the game!\n Rules:\nAll entries should be lowercase one character long.\n");
        PrintBoard();
        printf("Please place your Carrier (5 spaces long). Enter row charater, colomn number, and orientation ");
        scanf("%i %i %s", xPos, yPos, direction);
    //    playerBoard.placeShip(playerBoard.ship(), xPos, yPos, direction);
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

void PlayerTurn(int turn){
    bool player1Turn;
    bool player2Turn;
      while (turn < 100) {
          int r = 0;
          int c = 0;
          int count = 0;
          char c1 = 't';
 
          if (turn % 2 == 0){
              player1Turn = true;
          }
          else {
              player2Turn = true;
          }
 /*
          cout << "Row: ";
          cin >> r;
          cout << "Column: ";
          cin >> c;
 
          if ((r >= size) || (r < 0)){
              return 1;
          } else if ((c >= size) || (c < 0)){
              return 1;
          }
 
          if (board[r][c] != '-'){
              cout << "Spot " << board[r][c] << " already chosen." << endl;
              continue;
          }
 
          board[r][c] = player;
 
          cout << "  ";
          for (int i = 0; i < size; i++){
              cout << i << " ";
          }
          cout << endl;
 
          for(i = 0; i < size; i++) {
              cout << i << " ";
              for(j = 0; j < size; j++) {
                 cout << board[i][j] << " ";
              }
             cout << "\n";
       */
       }
    }
