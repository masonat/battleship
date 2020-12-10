#ifndef TURNEROOPFINAL_COMPUTER_H
#define TURNEROOPFINAL_COMPUTER_H


#include "Player.h"

class Computer: public Player {
private:

public:
    // constructors
    Computer(); // default constructor

    // methods + functions
    void takeShot(Grid &gridObj);

};

//virtual void takeShot();
//void updateBoard();
//void checkWinner();
//
// //getters
//string getPlayerName(){return playerName;};
//Grid getPlayerGrid(){return playerGrid;};
//
// //setters
//void setPlayerName(string newPlayerName){ playerName = newPlayerName;};
//void setPlayerGrid(Grid newPlayerGrid){playerGrid = newPlayerGrid;};

#endif //TURNEROOPFINAL_COMPUTER_H
