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

    Grid playerGrid;
    playerGrid.setBoard(playerShipVec, playerGrid);
    playerGrid.checkValidity(); // checks board for valid placement


    Grid computerGrid;
    computerGrid.setBoard(computerShipVec, computerGrid);
    computerGrid.checkValidity(); // checks board for valid placement


    Human hPlayer;
    Computer cPlayer;

    Player *humanPointer, *computerPointer;

    humanPointer = &hPlayer;
    computerPointer = &cPlayer;



    int menu = 0;

    while (menu!= 2) { // menu showing the options of the program
        cout << "1. Play Game\n";
        cout << "2. Exit Program\n";


        cin >> menu;

        switch (menu) {
            case 1:
                for(int i = 0; i < 25; i ++){ // plays game and checks for winner after every turn
                    hPlayer.takeShot(computerGrid, playerGrid);
                    humanPointer->checkWinner(hPlayer);
                    cPlayer.takeShot(playerGrid);
                    computerPointer->checkWinner(cPlayer);

                }
                break;

            case 2:
                cout << "Exiting program" << endl;
                cout << "=== Player Board ===" << endl;
                playerGrid.printBoard();
                cout << endl << endl << endl;
                cout << "=== Computer Board ===" << endl;
                computerGrid.printBoard();
                cout << endl << endl << endl;
                exit(0);

            default:
                cout << "Invalid input. Please read menu and try again\n"; // return to menu if invalid input

        }
    }
    return 0;
}