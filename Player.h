#ifndef TURNEROOPFINAL_PLAYER_H
#define TURNEROOPFINAL_PLAYER_H

#include "Grid.h"

using namespace std;

class Player {
private:
    string playerName;
    Grid playerGrid;
    int carrierCounter;
    int battleshipCounter;
    int cruiserCounter;
    int submarineCounter;
    int destroyerCounter;


public:
    // constructors
    Player();
    Player(string name);

    // functions + methods
    virtual void takeShot();
    void checkWinner(Player pObj);
    void updateCounter(char counterChar);
    void whichShip(char counterChar);


        //getters
    string getPlayerName(){return playerName;};
    Grid getPlayerGrid(){return playerGrid;};

    int getCarrierCounter() const {return carrierCounter;};
    int getBattleshipCounter() const {return battleshipCounter;};
    int getCruiserCounter() const {return cruiserCounter;};
    int getSubmarineCounter() const {return submarineCounter;};
    int getDestroyerCounter() const {return destroyerCounter;};


    //setters
    void setPlayerName(string newPlayerName){ playerName = newPlayerName;};
    void setPlayerGrid(Grid newPlayerGrid){ playerGrid = newPlayerGrid;};

    void setCarrierCounter(int newCCounter){ carrierCounter = newCCounter;};
    void setBattleshipCounter(int newBCounter){ battleshipCounter = newBCounter;};
    void setCruiserCounter(int newRCounter){ cruiserCounter = newRCounter;};
    void setSubmarineCounter(int newSCounter){ submarineCounter = newSCounter;};
    void setDestroyerCounter(int newDCounter){ destroyerCounter = newDCounter;};

};


#endif //TURNEROOPFINAL_PLAYER_H
