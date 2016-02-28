#include "Food.h"
#include "Settings.h"
#include <GL/freeglut.h>

// move food out of screen
Food::Food()
    : x(-1)
    , y(-1)
{

}

void Food::draw()
{
    const int scaledX = x * Settings::scale;
    const int scaledY = y * Settings::scale;

    // draw white food rectangle
    glColor3f(1,1,1);
    glVertex2f(scaledX, scaledY);
    glVertex2f(scaledX + Settings::scale, scaledY);
    glVertex2f(scaledX + Settings::scale, scaledY + Settings::scale);
    glVertex2f(scaledX, scaledY + Settings::scale);
}

// find appropriate cell for new food rectangle
void Food::spawn(const snake& player)
{
    do
    {
        x = (rand()%Settings::WIDTH);
        y = (rand()%Settings::HEIGHT);
    }while (!player.notSnakeCoords(x, y));
}
