//
// Created by Brian McKenna on 02/04/2021.
//
#include <iostream>
#include "Bug.h"
#include "Board.h"

// default constructor
Bug::Bug() {
}

// non default constructor
Bug::Bug(int id, const pair<int, int> &position, int direction, int size, bool alive,
         const list<pair<int, int>> &path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path.push_back(position);
}

int Bug::getId() const {
    return id;
}

const pair<int, int> &Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

const list<pair<int, int>> &Bug::getPath() const {
    return path;
}

void Bug::setId(int id) {
    Bug::id = id;
}

void Bug::setPosition(const pair<int, int> &position) {
    Bug::position = position;
}

void Bug::setDirection(int direction) {
    Bug::direction = direction;
}

void Bug::setSize(int size) {
    Bug::size = size;
}

void Bug::setAlive(bool alive) {
    Bug::alive = alive;
}

void Bug::setPath(const list<pair<int, int>> &path) {
    Bug::path = path;
}

Bug::~Bug() {
//    cout << "~Bug() called. Base destructor is called after derived destructor.\n";
}

// Checks if a bug is against an edge of the board AND if it is facing in the direction of that edge. If so, its way is blocked.
//  [Used by the move() function]

bool Bug::isWayBlocked() {

    bool isBlocked = false;

    if(this->getDirection() == 1 && this->getPosition().second ==  0) // north
    {
        cout << "\nFacing north";
        isBlocked = true;
    }
    else if(this->getDirection() == 2 && this->getPosition().first ==  9) // east
    {
        cout << "\nFacing East";
        isBlocked = true;
    }
    else if(this->getDirection() == 3 && this->getPosition().second ==  9) // south
    {
        cout << "\nFacing south";
        isBlocked = true;
    }
    else if(this->getDirection() == 4 && this->getPosition().first ==  0) // west
    {
        cout << "\nFacing West";
        isBlocked = true;
    }
    return isBlocked;
}

void Bug::print() {
    cout << "ID: " << id  << ", Position(x: " << position.first << "," << " y:" << position.second << "), "
    << "direction: " << direction << ", size: " << size << ", alive: " << alive;

    // add in path later
}







