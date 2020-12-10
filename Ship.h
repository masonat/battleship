#ifndef BATTLESHIPFINAL_SHIPS_H
#define BATTLESHIPFINAL_SHIPS_H

#include <string>
#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

enum Orientation { H = 0, V = 1};


class Ship {
    string shipName;
    Point location; // includes 1st and second coordinate 1st rows second column
    Orientation vOrH; //  for ship orientation horizontal = 0, vertical = 1
    char shipIcon;

public:
    // constructors
    Ship(); // default constructor

    // functions + methods
    static void LoadShips(std::vector<Ship> &shipVec);

    // getters
    string getShipName( ) const { return shipName; };
    Point getLocation( ) const { return location; };
    int getVOrH( ) const { return vOrH; };
    char getShipIcon() const { return shipIcon;};

    // setters
    void setShipName(string newShipName ) { shipName = newShipName; };
    void setLocation(Point newLocation) { location = newLocation; };
    void setVOrH(Orientation newVOrH) { vOrH = newVOrH; };
    void setShipIcon(char newShipIcon) { shipIcon = newShipIcon; };

};




#endif //BATTLESHIPFINAL_SHIPS_H
