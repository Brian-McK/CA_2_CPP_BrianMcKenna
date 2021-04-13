//
// Created by Brian McKenna on 02/04/2021.
//
#include <iostream>
#include "Bug.h"

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
    this->path = path;
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
    cout << "~Bug() called. Base destructor is called after derived destructor.\n";
}

// Checks if a bug is against an edge of the board AND if it is facing in the direction of that edge. If so, its way is blocked.
//  [Used by the move() function]

bool Bug::isWayBlocked() {
    if()
    {

    }

    return false;
}







