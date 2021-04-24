//
// Created by Brian McKenna on 13/04/2021.
//

#include "Board.h"

Board::Board(int width, int height) : width(width), height(height) {
    this->width = width;
    this->height = height;
}

int Board::getWidth() const {
    return width;
}

void Board::setWidth(int width) {
    Board::width = width;
}

int Board::getHeight() const {
    return height;
}

void Board::setHeight(int height) {
    Board::height = height;
}

