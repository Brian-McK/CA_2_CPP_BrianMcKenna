//
// Created by Brian McKenna on 13/04/2021.
//

#ifndef CA2_BRIAN_MCKENNA_BOARD_H
#define CA2_BRIAN_MCKENNA_BOARD_H


class Board {
private:
    int length = 10;
    int width = 10;
public:
    int getLength() const;

    void setLength(int length);

    int getWidth() const;

    void setWidth(int width);

    Board(int length, int width);
};


#endif //CA2_BRIAN_MCKENNA_BOARD_H
