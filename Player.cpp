//
// Created by mason on 12/6/2020.
//

#include "Player.h"

Player::Player() {

    playerName = "Default Name";
    carrierCounter = 0;
    battleshipCounter = 0;
    cruiserCounter = 0;
    submarineCounter = 0;
    destroyerCounter = 0;
}

void Player::takeShot() {
    cout << "Player class takeshot() called" << endl;
}

void Player::checkWinner(Player pObj) { // dont think i have LOGICAL STATEMENTS RIGHT
   // if carrierCounter, battleshipCounter, cruiserCounter, submarineCounter, destroyerCounter
   // are ALL greater than 0
   // winner is determined
   // for example if all HUMAN counters are 1 then HUMAN WINS
   if (!(carrierCounter == 0 && battleshipCounter == 0 && cruiserCounter == 0
        && submarineCounter == 0 &&  destroyerCounter == 0)){
        cout << "The winner is " << getPlayerName() << endl;
        // print boards and all guesses
        exit(0);
   }
}

void Player::updateCounter(char counterChar) {
    if(counterChar == 'C'){
        carrierCounter++;
    }
    if(counterChar == 'B'){
        battleshipCounter++;
    }
    if(counterChar == 'R'){
        cruiserCounter++;
    }
    if(counterChar == 'S'){
        submarineCounter++;
    }
    if(counterChar == 'D'){
        destroyerCounter++;
    }


}

void Player::whichShip(char counterChar) {
    if(counterChar == 'C'){
        cout << " Carrier";
    }
    if(counterChar == 'B'){
        cout << " Battleship";
    }
    if(counterChar == 'R'){
        cout << " Cruiser";
    }
    if(counterChar == 'S'){
        cout << " Submarine";
    }
    if(counterChar == 'D'){
        cout << " Destroyer";
    }


}





