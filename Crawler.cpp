//
// Created by Brian McKenna on 06/04/2021.
//

#include "Crawler.h"
#include <iostream>
using namespace std;

Crawler::Crawler() {

}

void Crawler::move() {
    cout << "Moving the Crawler...\nDone Moving." << endl;
}

Crawler::~Crawler() {
    cout << "~Crawler() destructor called.\n";
}

Crawler::Crawler(int id, const pair<int, int> &position, int direction, int size, bool alive,
                 const list<pair<int, int>> &path) : Bug(id, position, direction, size, alive, path) {

}
