
#include "Ship.h"
#include <fstream>
#include <vector>

Ship::Ship() {
    shipName = "Default Ship";
    location.coordinate1 = 0;
    location.coordinate2 = 0;
    vOrH = H;
    shipIcon = 'D';
}

void Ship::LoadShips(std::vector<Ship> &shipVec) {

    // open input file stream
    /*string fileName;
    cout << "Enter file name for player first and press enter." << endl;
    cout << "Then enter file name for computer and press enter." << endl;
    cin >> fileName;*/

    std::ifstream inputFile;
    inputFile.open("ship1.csv");


    if (inputFile.fail()) {
        cerr << "File failed to open" << endl;
        exit(1); // if file doesn't open exit program
    }

    string aShipName;
    string coordinates;
    string anOrientation;
    char firstCoordinate;
    int secondCoordinate;
    char finalOrientation;

    Ship tempShip;

    while(inputFile.good()){
        getline(inputFile, aShipName, ','); // get shipName
        getline(inputFile, coordinates, ','); // get row AND column
        getline(inputFile, anOrientation, '\n'); // get ship orientation in form of a letter

        char actualOrientation;

        for (auto c : anOrientation) // this function accounts for any possible white space after orientation
        {
          if (c != ' ')
          {
            actualOrientation = c;
            break;
          }
        }

        firstCoordinate = coordinates[1];
        secondCoordinate = coordinates[0];

        if (actualOrientation == 'H'){
            finalOrientation = 0;
        }
        else if (actualOrientation == 'V'){
            finalOrientation = 1;
        }
        else{
            std::cout << actualOrientation << std::endl;
            cerr << "Orientation not valid. Please check source file.\n";
            exit(1); // error checking for orientation
        }

        tempShip.setShipName(aShipName);
        tempShip.location.coordinate1 = firstCoordinate - 49; // subtract 64 for ASCII code + 1 bc array starts at 0
        tempShip.location.coordinate2 = secondCoordinate - 65; // subtract 48 for ASCII code + 1 bc array starts at 0
        tempShip.vOrH = (Orientation)finalOrientation;

        shipVec.push_back(tempShip);
    }

    /*for (auto s : shipVec) // for testing purposes
   {
        cout << "Ship Name: "<< s.shipName << std::endl;
        cout << "First coordinate for array: " << s.location.coordinate1 << " ";
        cout << "Second coordinate for array: " << s.location.coordinate2 << endl;
        cout << s.vOrH << endl;
    }*/

    inputFile.close();

}

