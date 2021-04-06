//
// Created by Brian McKenna on 06/04/2021.
//

#include "Crawler.h"
#include <iostream>
using namespace std;

void move() {	// implementation of move()
    cout << "moving the Crawler...\ndone moving." << endl;
}
Crawler::~Crawler() noexcept {
    cout << "~Crawler() destructor called.\n";
}
