//
// Created by Brian McKenna on 06/04/2021.
//

#include "Hopper.h"
#include <iostream>
using namespace std;

Hopper::Hopper(int hopLength) : hopLength(hopLength) {
    this->hopLength = hopLength;
}

void Hopper::move() {
    cout << "Moving the Hopper...\nDone Moving." << endl;
}

Hopper::~Hopper() {
    cout << "~Hopper() destructor called.\n";
}

int Hopper::getHopLength() const {
    return hopLength;
}

void Hopper::setHopLength(int hopLength) {
    Hopper::hopLength = hopLength;
}

Hopper::Hopper() {
}
