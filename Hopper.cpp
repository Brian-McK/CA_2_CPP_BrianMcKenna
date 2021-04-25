//
// Created by Brian McKenna on 06/04/2021.
//

#include "Hopper.h"
#include <iostream>
using namespace std;

Hopper::Hopper(int id, const pair<int, int> &position, int direction, int size, bool alive,
               const list<pair<int, int>> &path, int hopLength) : Bug(id, position, direction, size, alive, path),
                                                                  hopLength(hopLength) {
    this->hopLength = hopLength;
}

void Hopper::move() {

    // before I set the move I need to check if the way is blocked
    // if the way is not blocked I then set the new position with the hopLength
    // if the new position is greater or equal I then need to set to the edge of the board

    if(!this->isWayBlocked())
    {
        cout << "\nThe way is not blocked" << endl;

        // TODO - SET A NEW DIRECTION IF AT EDGE OF BOARD AND CANT MOVE THAT WAY

        if(this->getDirection() == 1) // north
        {
            if(this->getPosition().second - this->getHopLength() <= 0)
            {
                // TODO - set new random direction - random number between 1 & 4 but not including the current direction
                this->setPosition(pair<int, int>(this->getPosition().first,0));
            } else {
                this->setPosition(pair<int, int>(this->getPosition().first,(this->getPosition().second - this->hopLength)));
            }
        }
        if(this->getDirection() == 2) // east
        {
            if(this->getPosition().first + this->getHopLength() >= 9)
            {
                this->setPosition(pair<int, int>(9,this->getPosition().second));
            } else {
                this->setPosition(pair<int, int>((this->getPosition().first + this->hopLength),this->getPosition().second));
            }
        }
        if(this->getDirection() == 3) // south
        {
            if(this->getPosition().second + this->getHopLength() >= 9)
            {
                this->setPosition(pair<int, int>(this->getPosition().first,9));
            } else {
                this->setPosition(pair<int, int>(this->getPosition().first,(this->getPosition().second + this->hopLength)));
            }
        }
        if(this->getDirection() == 4) // west
        {
            if(this->getPosition().first - this->getHopLength() <= 0)
            {
                this->setPosition(pair<int, int>(0,this->getPosition().second));
            } else {
                this->setPosition(pair<int, int>((this->getPosition().first - this->hopLength),this->getPosition().second));
            }
        }
    }
    else
    {
        cout << "\nThe way is blocked" << endl;
    }
    cout << "\nMoving the Hopper...Done Moving." << endl;
}

Hopper::~Hopper() {
//    cout << "~Hopper() destructor called.\n";
}

Hopper::Hopper() {
}

int Hopper::getHopLength() const {
    return hopLength;
}

void Hopper::setHopLength(int hopLength) {
    Hopper::hopLength = hopLength;
}

void Hopper::print() {
    cout << "Hopper: ";
    Bug::print(); cout << ", hopLength:" << hopLength;
}
