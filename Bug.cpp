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
         const list<pair<int, int>> &path, int hopLength) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
    this->hopLength = hopLength;
}

Bug::Bug(int id, const pair<int, int> &position, int direction, int size, bool alive,
         const list<pair<int, int>> &path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
    this->hopLength = 0;
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

int Bug::getHopLength() const {
    return hopLength;
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

void Bug::setHopLength(int hopLength) {
    Bug::hopLength = hopLength;
}

Bug::~Bug() {
    cout << "~Bug() called. Base destructor is called after derived destructor.\n";
}









