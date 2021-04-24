//
// Created by Brian McKenna on 13/04/2021.
//

#ifndef CA2_BRIAN_MCKENNA_BOARD_H
#define CA2_BRIAN_MCKENNA_BOARD_H


class Board {
private:
    int width = 10;
    int height = 10;
public:

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    Board(int width, int height);
};


#endif //CA2_BRIAN_MCKENNA_BOARD_H
