#include "Snake.h"
#include "Settings.h"
#include <GL/freeglut.h>
#include <string.h>

snake::snake()
{
    init();
}

void snake::init()
{
    turn = false;
    size = Settings::StartSize;
    direction = GLUT_KEY_UP;

    memset(blocks, 0x00, Settings::WIDTH*Settings::HEIGHT);

    blocks[0].x = Settings::StartPosX;
    blocks[0].y = Settings::StartPosY;
}

void snake::DrawSnake()
{
    for (int i = 0; i < size; i++)
        blocks[i].draw();
}

void snake::move()
{
    for(int i = size; i > 0; i--)
    {
        blocks[i].x = blocks[i-1].x;
        blocks[i].y = blocks[i-1].y;
    }

    switch (direction)
    {
    case GLUT_KEY_UP :
        blocks[0].y++;
        break;
    case GLUT_KEY_DOWN :
        blocks[0].y--;
        break;
    case GLUT_KEY_LEFT :
        blocks[0].x--;
        break;
    case GLUT_KEY_RIGHT :
        blocks[0].x++;
        break;
    }

    // out of screen
    if(blocks[0].x < 0)
        blocks[0].x += Settings::WIDTH;
    if(blocks[0].x >= Settings::WIDTH)
        blocks[0].x -= Settings::WIDTH;
    if(blocks[0].y < 0)
        blocks[0].y += Settings::HEIGHT;
    if(blocks[0].y >= Settings::HEIGHT)
        blocks[0].y -= Settings::HEIGHT;
}

bool snake::eat(const int foodX, const int foodY)
{
    if (blocks[0].x == foodX && blocks[0].y == foodY)
    {
        size++;
        return true;
    }

    return false;
}

bool snake::isBiteYourself()
{
    for (int i = 3; i < size; i++)
    {
        if (blocks[0].x == blocks[i].x && blocks[0].y == blocks[i].y)
        {
            size = i;
            return true;
        }
    }
    return false;
}

bool snake::notSnakeCoords(int x, int y) const
{
    for (int i = 0; i < size; i++)
    {
        if (x == blocks[i].x && y==blocks[i].y)
            return false;
    }
    return true;
}

