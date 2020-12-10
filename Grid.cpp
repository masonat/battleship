//
// Created by mason on 12/3/2020.
//

#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid() {
    //cout << "Default Grid constructor" << endl;
    for (int x = 0; x < BOARD_ROWS; ++x) {
        for (int y = 0; y < BOARD_COLUMNS; ++y) {
            board[x][y] = '~';
        }
    }

}

void Grid::setBoard(vector<Ship> shipVectorName, Grid &gridName) {

    for (auto s : shipVectorName) // for testing purposes
    {
        if (s.getShipName() == "Carrier") {

            s.setShipIcon('C');

            if (s.getVOrH() == 1) { // vertical

                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon(); // starting coordinates
                board[s.getLocation().coordinate1 + 1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 2][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 3][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 4][s.getLocation().coordinate2] = s.getShipIcon();
            }  // end of carrier vertical

            if (s.getVOrH() == 0) { // horizontal

                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon(); // starting coordinates
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 1] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 3] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 4] = s.getShipIcon();
            }  // end of carrier horizontal
        } // end for carrier
        if (s.getShipName() == "Battleship") {

            s.setShipIcon('B');

            if (s.getVOrH() == 1) { // vertical + add to x
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 2][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 3][s.getLocation().coordinate2] = s.getShipIcon();
            }  // end of battleship vertical
            if (s.getVOrH() == 0) { // horizontal
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 1] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 3] = s.getShipIcon();
            } // end of battleship horizontal
        } // end for battleship
        if (s.getShipName() == "Cruiser") {

            s.setShipIcon('R');

            if (s.getVOrH() == 1) { // vertical + add to x
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 2][s.getLocation().coordinate2] = s.getShipIcon();
            }  // end of cruiser vertical
            if (s.getVOrH() == 0) { // horizontal
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 1] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 2] = s.getShipIcon();
            } // end of cruiser horizontal
        } // end for cruiser
        if (s.getShipName() == "Submarine") {

            s.setShipIcon('S');

            if (s.getVOrH() == 1) { // vertical + add to x
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 2][s.getLocation().coordinate2] = s.getShipIcon();
            }  // end of Submarine vertical
            if (s.getVOrH() == 0) { // horizontal
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 1] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 2] = s.getShipIcon();
            } // end of Submarine horizontal
        } // end for Submarine
        if (s.getShipName() == "Destroyer") {

            s.setShipIcon('D');

            if (s.getVOrH() == 1) { // vertical
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1 + 1][s.getLocation().coordinate2] = s.getShipIcon();
            }  // end of destroyer vertical
            if (s.getVOrH() == 0) { // horizontal
                board[s.getLocation().coordinate1][s.getLocation().coordinate2] = s.getShipIcon();
                board[s.getLocation().coordinate1][s.getLocation().coordinate2 + 1] = s.getShipIcon();
            } // end of destroyer horizontal
        } // end for destroyer

    } // end of for auto loop
} // end of function declaration

void const Grid::checkValidity() { // if all these add up to expected totals all criteria for placing ships must be meant

    int validWater {0}, validCarrier {0}, validCruiser {0}, validSubmarine {0}, validDestroyer {0}, validBattleship {0};

    for (int x = 0; x < BOARD_ROWS; ++x) {
        for (int y = 0; y < BOARD_COLUMNS; ++y) {
            if(board[x][y] == 'C'){
                validCarrier++; // total should be 5
            }
            if(board[x][y] == 'B'){
                validBattleship++; // total should be 4
            }
            if(board[x][y] == 'R'){
                validCruiser++; // total should be 3
            }
            if(board[x][y] == 'S'){
                validSubmarine++; // total should be 3
            }
            if(board[x][y] == 'D'){
                validDestroyer++; // total should be 2
            }
            if(board[x][y] == '~'){
                validWater++; // total should be 83
            }
        }
    }
    if((validCarrier == 5) && (validBattleship == 4) && (validCruiser == 3) && (validSubmarine == 3) && (validDestroyer == 2)  && (validWater == 83)){
        cout << "Valid placement, thank you!" << endl;
    }
    else{
        cerr << "Placement was invalid. Please check input file and make sure that it meets all requirements" << endl;
        exit(1);
    }
}

void Grid::printBoard() {
    cout << "    A B C D E F G H I J" << endl;
    cout << "    % % % % % % % % % %" << endl;
    for (int i = 0; i < BOARD_ROWS; i++){
        cout << i + 1 << " % ";
        for (int j = 0; j < BOARD_COLUMNS; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


