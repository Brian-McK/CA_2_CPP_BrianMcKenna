//
// Created by Brian McKenna on 06/04/2021.
//

#ifndef CA2_BRIAN_MCKENNA_HOPPER_H
#define CA2_BRIAN_MCKENNA_HOPPER_H

#include "Bug.h"
#include <iostream>

using namespace std;

class Hopper: public Bug {
private:
    int hopLength;
public:
    int getHopLength() const;
    void setHopLength(int hopLength);
    void move();
    ~Hopper();
    Hopper();

    Hopper(int id, const pair<int, int> &position, int direction, int size, bool alive,
           const list<pair<int, int>> &path, int hopLength);
};


#endif //CA2_BRIAN_MCKENNA_HOPPER_H
