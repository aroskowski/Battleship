#include "BATTLESHIP_H"
#include <iomanip>

using namespace std;

int main(){
    int turnNum = 0;
    char play;

    printf("Would you like to play a game? (y or n)");
    cin << play;
    while(play == y){
        printf("\nWelcome to the game!\n");
        play = n;
    }

    return 0;
}