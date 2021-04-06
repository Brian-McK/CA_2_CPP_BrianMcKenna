//
// Created by Brian McKenna on 06/04/2021.
//

#ifndef CA2_BRIAN_MCKENNA_HOPPER_H
#define CA2_BRIAN_MCKENNA_HOPPER_H

#include "Bug.h"

using namespace std;


class Hopper: public Bug {
private:
    int hopLength;
public:
    int getHopLength() const;
    void setHopLength(int hopLength);
    ~Hopper();

    void move();
};


#endif //CA2_BRIAN_MCKENNA_HOPPER_H
