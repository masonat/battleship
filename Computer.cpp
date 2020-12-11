//
// Created by mason on 12/4/2020.
//

#include "Computer.h"

#include <cstdlib> // srabd
#include <ctime> // time

Computer::Computer() {
    setPlayerName("Computer");
}


void Computer::takeShot(Grid &gridObj) {

    int charInput;
    int intInput;
    char counterUpdater;


    srand(time(NULL));

    charInput = (rand() % 9);
    //cout << "First " << charInput << endl; // for testing

    intInput = (rand() % 10);
    //cout << "Second " << intInput << endl; // for testing





    if (gridObj.board[intInput][charInput] == '~'){
        cout << "Computer missed at " << charInput + 1 << " " << to_string(intInput + 1) << endl;
        gridObj.board[intInput][charInput] = 'X'; // for a miss the board updates to X
    }

    else if (gridObj.board[intInput][charInput] != '~'){  
        counterUpdater = gridObj.board[intInput][charInput];
        updateCounter(counterUpdater); // updates computer counters!
        cout << "Computer hit your "; whichShip(counterUpdater);
        cout << "! At " << charInput + 1 << " " << to_string(intInput + 1) << endl;

        for (int x = 0; x < 10; ++x) { // update board if hit
            for (int y = 0; y < 10; ++y) {
                if(gridObj.board[x][y] == counterUpdater)
                    gridObj.board[x][y] = 'O';
            }
        }
        gridObj.board[intInput][charInput] = 'O'; // for a hit the board shows O
    }

    gridObj.printBoard();

}