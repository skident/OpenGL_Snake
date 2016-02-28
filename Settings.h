#ifndef GAME_H
#define GAME_H


class Settings
{
public:
    enum eDimension
    {
        WIDTH = 80,
        HEIGHT = 45
    };

    enum eLimits
    {
        StartSize   = 3,
        StartPosX   = (int)(WIDTH/2),
        StartPosY   = (int)(HEIGHT/2),
        delay       = 100,
        scale       = 1,
        WinScale    = 10,
        WinPosX     = 200,
        WinPosY     = 0,
    };
};

#endif // GAME_H
