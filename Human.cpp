#include "Human.h"


Human::Human() {
    setPlayerName("Human Player");
}


void Human::takeShot(Grid &gridObj) { // should pass in COMPUTER OBJECT


    char charInput;
    int intInput;
    char counterUpdater;

    char quit;
    while (quit != 'N') { // allow user to quit at beginning of each turn
        cout << "Would you like to quit the game? (N) for no, (Q) for yes." << endl;
        cin >> quit;
        if (quit == 'Q') {
            cout << "You have quit the game" << endl;
            // print boards and guesses !#%@#^^#!@#@$
            exit(1);
            // display final boards
        } else if (quit == 'N') {
            // just continue on in stuff
        } else {
            cout << "That wasn't an option\n";
            cout << "Try again\n";
        }
    }  // allow user to quit at beginning of each turn


    cout << "Where would you like to fire a missile?\n"
            "Please enter a UPPERCASE letter first followed by a space followed by a number\n"
            "Example C 4\n" << endl;
    cin >> charInput >> intInput;

    int humanRow = (int)charInput - 65;
    int humanColumn = intInput - 1;

    cout << (int)charInput - 65 << " , " << intInput - 1 << endl; // for testing


    //cout << gridObj.board[humanRow][humanColumn] << "!!!!!!!!!!!!\n"; // for testing

    if (gridObj.board[humanColumn][humanRow] == '~'){ // ~ represents water
        cout << "You missed!" << endl;
        gridObj.board[humanColumn][humanRow] = 'X'; // for a miss the board updates to X
    }
    else{
        counterUpdater = gridObj.board[humanColumn][humanRow];
        updateCounter(counterUpdater);
        cout << "You hit the "; whichShip(counterUpdater); cout << "!" << endl;

        for (int x = 0; x < 10; ++x) { // update board if hit
            for (int y = 0; y < 10; ++y) {
                if(gridObj.board[x][y] == counterUpdater)
                    gridObj.board[x][y] = 'O';
            }
        }
        gridObj.board[humanColumn][humanRow] = 'O'; // for a hit the board shows O
    }

    gridObj.printBoard();

}




