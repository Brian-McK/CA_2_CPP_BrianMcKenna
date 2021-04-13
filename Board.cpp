//
// Created by Brian McKenna on 13/04/2021.
//

#include "Board.h"

int Board::getLength() const {
    return length;
}

void Board::setLength(int length) {
    Board::length = length;
}

int Board::getWidth() const {
    return width;
}

void Board::setWidth(int width) {
    Board::width = width;
}

Board::Board(int length, int width) : length(length), width(width) {
    this->length = length;
    this->width = width;
}
