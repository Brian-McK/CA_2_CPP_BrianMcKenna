//
// Created by Brian McKenna on 06/04/2021.
//

#include "Hopper.h"
#include <iostream>
using namespace std;

void Hopper::move() {
    cout << "Moving the Hopper...\nDone Moving." << endl;
}

Hopper::~Hopper() {
    cout << "~Hopper() destructor called.\n";
}

Hopper::Hopper() {
}
