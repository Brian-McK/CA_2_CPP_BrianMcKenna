//
// Created by Brian McKenna on 06/04/2021.
//

#pragma once
#ifndef CA2_BRIAN_MCKENNA_CRAWLER_H
#define CA2_BRIAN_MCKENNA_CRAWLER_H
#include "Bug.h"

class Crawler: public Bug {
public:
    ~Crawler();
    virtual void move();
};

#endif //CA2_BRIAN_MCKENNA_CRAWLER_H
