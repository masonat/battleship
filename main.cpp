#include <iostream>
#include "Ship.h"
#include "Grid.h"
#include "Human.h"
#include "Computer.h"
#include <unistd.h> // for sleep function for testing

using namespace std;

int main() {

    vector<Ship> computerShipVec; // a vector of Ship objects called shipVec
    vector<Ship> playerShipVec; // a vector of Ship objects called shipVec


    Ship::LoadShips(playerShipVec); // load ships into player ship vector
    Ship::LoadShips(computerShipVec); // load ships into computer ship vector

    Grid playerGrid, playerGuessGrid;
    playerGrid.setBoard(playerShipVec, playerGrid);
    /*cout << "Human Board" << endl;
    playerGrid.printBoard();*/
    playerGrid.checkValidity();


    Grid computerGrid;
    computerGrid.setBoard(computerShipVec, computerGrid);
    computerGrid.checkValidity();


    /*cout << "Computer Board" << endl;
    computerGrid.printBoard();*/

    Human hPlayer;
    Computer cPlayer;

    Player *humanPointer, *computerPointer;

    humanPointer = &hPlayer;
    computerPointer = &cPlayer;

    hPlayer.takeShot(computerGrid);
    humanPointer->checkWinner(hPlayer);

/*    for(int i = 0; i < 10; i ++){
        hPlayer.takeShot(computerGrid);
        cPlayer.takeShot(computerGrid);
    }*/

/*    for(int i = 0; i < 10; i++){
        usleep(1500000); // sleep for 1.5 seconds FOR TESTING
        cPlayer.takeShot(playerGrid);
        //computerPointer->checkWinner(cPlayer);

    }*/


    return 0;
}