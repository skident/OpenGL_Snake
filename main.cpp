#include <iostream>
#include <GL/freeglut.h>
#include <time.h>
#include "Settings.h"
#include "Food.h"
#include "Snake.h"
#include "Block.h"

using namespace std;

snake player;
Food food;

/***************************/
void keyboard(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if ((player.direction != GLUT_KEY_DOWN)&&player.turn)
            player.direction = GLUT_KEY_UP;
        player.turn = false;
        break;
    case GLUT_KEY_DOWN:
        if((player.direction!=GLUT_KEY_UP)&&player.turn)
            player.direction=GLUT_KEY_DOWN;
        player.turn = false;
        break;
    case GLUT_KEY_LEFT:
        if((player.direction!=GLUT_KEY_RIGHT)&&player.turn)
            player.direction=GLUT_KEY_LEFT;
        player.turn = false;
        break;
    case GLUT_KEY_RIGHT:
        if((player.direction!=GLUT_KEY_LEFT)&&player.turn)
            player.direction=GLUT_KEY_RIGHT;
        player.turn = false;
        break;
    }
}

void Timer(int value)
{
    player.turn = true;

    player.move(); // move snake

    // check is snake bite itself
    if (player.isBiteYourself())
    {
        // restart game

        // TODO: need menu or something like that
        player.init();
        glutPostRedisplay();
        glutTimerFunc(Settings::delay, Timer, 0);
        return;
    }

    // Check is player ate food
    if (player.eat(food.x, food.y))
    {
        food.spawn(player); // generate new food cell
    }

    glutPostRedisplay();
    glutTimerFunc(Settings::delay, Timer, 0);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    food.draw();
    player.DrawSnake();
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    food.spawn(player);
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Settings::WIDTH*Settings::WinScale, Settings::HEIGHT*Settings::WinScale);
    glutInitWindowPosition(Settings::WinPosX, Settings::WinPosY);
    glutCreateWindow("***SNAKE***");
    glutDisplayFunc(draw);
    glutTimerFunc(Settings::delay, Timer, 0);
    glutSpecialFunc(keyboard);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Settings::WIDTH, 0, Settings::HEIGHT, -1, 1);
    glutMainLoop();

    return 0;
}

