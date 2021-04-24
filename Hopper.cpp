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
    cout << "Moving the Hopper...\nDone Moving." << endl;
}

Hopper::~Hopper() {
    cout << "~Hopper() destructor called.\n";
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
