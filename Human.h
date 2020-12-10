//
// Created by mason on 12/6/2020.
//

#ifndef TURNEROOPFINAL_HUMAN_H
#define TURNEROOPFINAL_HUMAN_H


#include "Player.h"

class Human: public Player {
private:

public:
    // constructors
    Human(); // default constructor

    // functions + methods
    void takeShot(Grid &gridObj);

};

#endif //TURNEROOPFINAL_HUMAN_H
