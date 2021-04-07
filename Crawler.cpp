//
// Created by Brian McKenna on 06/04/2021.
//

#include "Crawler.h"
#include <iostream>
using namespace std;

void Crawler::move() {
    cout << "Moving the Crawler...\nDone Moving." << endl;
}

Crawler::~Crawler() {
    cout << "~Crawler() destructor called.\n";
}

Crawler::Crawler() {
}
