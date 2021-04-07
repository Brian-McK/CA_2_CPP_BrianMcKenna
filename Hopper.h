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
    Hopper(int hopLength);
    int getHopLength() const;
    void setHopLength(int hopLength);
    ~Hopper();
    void move();
    Hopper();
};


#endif //CA2_BRIAN_MCKENNA_HOPPER_H
