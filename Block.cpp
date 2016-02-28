#include "Block.h"
#include "Settings.h"
#include <GL/freeglut.h>

block::block()
    : x(-1)
    , y(-1)
{

}

void block::draw()
{
    const int scaledX = x * Settings::scale;
    const int scaledY = y * Settings::scale;

    // draw white square
    glColor3f(1,1,1);
    glVertex2f(scaledX, scaledY);
    glVertex2f(scaledX + Settings::scale, scaledY);
    glVertex2f(scaledX + Settings::scale, scaledY + Settings::scale);
    glVertex2f(scaledX, scaledY + Settings::scale);
}
