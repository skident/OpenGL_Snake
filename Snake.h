#ifndef SNAKE_H
#define SNAKE_H

#include "Block.h"
#include "Settings.h"

class snake
{
private:
    block blocks[Settings::WIDTH*Settings::HEIGHT];

public:
    int direction;
    int size;
    bool turn;

    snake();
    void init();
    void DrawSnake();
    bool isBiteYourself();
    void move();
    bool eat(const int foodX, const int foodY);
    bool notSnakeCoords(int x, int y) const;
};

#endif // SNAKE_H
