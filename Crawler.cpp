//
// Created by Brian McKenna on 06/04/2021.
//

#include "Crawler.h"
#include <iostream>
using namespace std;

Crawler::Crawler() {

}

void Crawler::move() {

    if(!this->isWayBlocked())
    {
        if(this->getDirection() == 1) // north
        {
            if(this->getPosition().second - 1 <= 0)
            {
                this->move();
            } else {
                this->setPosition(pair<int, int>(this->getPosition().first,(this->getPosition().second - 1)));
            }
        }
        if(this->getDirection() == 2) // east
        {
            if(this->getPosition().first + 1 >= 9)
            {
                this->move();
            } else {
                this->setPosition(pair<int, int>((this->getPosition().first + 1),this->getPosition().second));
            }
        }
        if(this->getDirection() == 3) // south
        {
            if(this->getPosition().second + 1 >= 9)
            {
                this->move();
            } else {
                this->setPosition(pair<int, int>(this->getPosition().first,(this->getPosition().second + 1)));
            }
        }
        if(this->getDirection() == 4) // west
        {
            if(this->getPosition().first - 1 <= 0)
            {
                this->move();
            } else {
                this->setPosition(pair<int, int>((this->getPosition().first - 1),this->getPosition().second));
            }
        }
        cout << "\nMoving the Crawler...Done Moving." << endl;
        this->print();
    }
    else
    {
        cout << "\nThe way is blocked, generating new random direction" << endl;

        srand(time(0));

        int newDirection = (rand() % 4) + 1;
        while (newDirection == this->getDirection())
        {
            newDirection = (rand() % 4) + 1;
        }
        cout << "New random direction: " << newDirection << endl;

        this->setDirection(newDirection);

        this->move();
    }
}

Crawler::~Crawler() {
//    cout << "~Crawler() destructor called.\n";
}

Crawler::Crawler(int id, const pair<int, int> &position, int direction, int size, bool alive,
                 const list<pair<int, int>> &path) : Bug(id, position, direction, size, alive, path) {

}

void Crawler::print() {
    cout << "Crawler: ";
    Bug::print();
}