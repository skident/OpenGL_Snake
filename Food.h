#ifndef FOOD_H
#define FOOD_H

#include "Snake.h"

class Food
{
public:
    int x;
    int y;

    Food();
    void draw();
    void spawn(const snake& player);
};

#endif // FOOD_H
