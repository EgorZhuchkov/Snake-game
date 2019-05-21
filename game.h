#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "mydefinitions.h"
#include "time.h"
#include <deque>
#include "snakepart.h"
#include <stdlib.h>
#include <unistd.h>

class game
{
    int speed, score, max_y, max_x, food_x, food_y;// direction, prev_dir;
    Direction direction, prevDirection;
    std::deque<snakePart> snake;
public:
    game(int gameSpeed);
    void play();
    void genFood();
    void drawMap();
    void drawFood();
    void drawSnake();
    void moveSnake(Direction dir);
    bool collision();
};

#endif // GAME_H
