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
     void move();
     void print();
     Crawler();

    Crawler(int id, const pair<int, int> &position, int direction, int size, bool alive,
            const list<pair<int, int>> &path);
};

#endif //CA2_BRIAN_MCKENNA_CRAWLER_H
