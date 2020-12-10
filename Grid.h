#ifndef TURNEROOPFINAL_GRID_H
#define TURNEROOPFINAL_GRID_H

#include "Ship.h"

const int BOARD_COLUMNS{10};
const int BOARD_ROWS{10};

class Grid {
private:
    char board[BOARD_ROWS][BOARD_COLUMNS];
public:
    // constructors
    Grid(); // default constructor

    //setter
    void setBoard (vector <Ship> name, Grid &gridName);

    // functions + methods
    void printBoard();
    void  const checkValidity();

    friend class Human;
    friend class Computer;

};


#endif //TURNEROOPFINAL_GRID_H
