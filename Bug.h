//
// Created by Brian McKenna on 02/04/2021.
//
#ifndef CA2_BRIAN_MCKENNA_BUG_H
#define CA2_BRIAN_MCKENNA_BUG_H
#include <string>
#include <utility>
#include <list>
#include <iostream>
#include "Board.h"

#pragma once

using namespace std;

class Bug {
private:
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
public:
    Bug();
    Bug(int id,
        const pair<int, int> &position,
        int direction,
        int size,
        bool alive,
        const list<pair<int, int>> &path);

    int getId() const;
    const pair<int, int> &getPosition() const;
    int getDirection() const;
    int getSize() const;
    bool isAlive() const;
    const list<pair<int, int>> &getPath() const;

    void setId(int id);
    void setPosition(const pair<int, int> &position);
    void setDirection(int direction);
    void setSize(int size);
    void setAlive(bool alive);
    void setPath(const list<pair<int, int>> &path);
    bool isWayBlocked();
    virtual void move() = 0;
    virtual void print();
    virtual ~Bug();
};


#endif //CA2_BRIAN_MCKENNA_BUG_H
