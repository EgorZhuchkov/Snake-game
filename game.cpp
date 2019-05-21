#include "game.h"


game::game(int gameSpeed) {
    getmaxyx(stdscr, max_y, max_x);
    speed = gameSpeed;
    score = 0;
    food_x = 0;
    food_y = 0;
    direction = RIGHT;
    prevDirection = RIGHT;
    for(int i = 0; i < 6; ++i) {
        snake.push_back(snakePart(max_x/2 + 3 - i, max_y/2));
    }
}

void game::genFood() {
        srand(time(NULL));
        food_y= random()%(max_y-6)+4;
        food_x= random()%(max_x-4)+2;
}

void game::drawMap() {
    box(stdscr, 0, 0);
    mvprintw(1,1, "SCORE: %d", score);
    mvprintw(2,1, "Press Q to quit");
    refresh();
}

void game::drawFood() {
    mvprintw(food_y, food_x, "F");
    refresh();
}

void game::drawSnake() {
    for(const snakePart &body : snake) {
        mvprintw(body.getY(), body.getX(), "%c", body.getCh());
        refresh();
    }
}
void game::moveSnake(Direction dir) {
    int newX = snake[0].getX();
    int newY = snake[0].getY();
    if(dir == UP)
        newY--;
    else if(dir == LEFT)
        newX--;
    else if(dir == DOWN)
        newY++;
    else if(dir == RIGHT)
        newX++;
    snakePart newHead(newX, newY);

    snake.push_front(newHead);
    if(newX == food_x && newY == food_y)  {
        score++;
        genFood();
        drawFood();
    }
    else {
        snake.pop_back();
    }
    drawSnake();
}

bool game::collision() {
    int headX = snake[0].getX();
    int headY = snake[0].getY();
    if((headX == max_x - 1) || (headY == 0) || (headX == 0) || (headY == max_y - 1)) {
        return true;
    }
    else {
        for(unsigned
            int i = 4; i < snake.size(); ++i) {
            if((headX == snake[i].getX()) && (headY == snake[i].getY())) {
                return true;
            }
        }
    }
    return false;
}

void game::play() {
    clear();
    drawMap();
    genFood();
    drawFood();
    drawSnake();

    int ch = 0;
    timeout(speed);
    while(((ch=getch())!= 'q')) {
        switch(ch)
        {
            case KEY_UP: direction= UP;
                    break;
            case KEY_DOWN: direction= DOWN;
                    break;
            case KEY_RIGHT: direction= RIGHT;
                    break;
            case KEY_LEFT: direction= LEFT;
                    break;
        }

        refresh();
        clear();
        drawMap();
        drawFood();
        if((direction + 2 == prevDirection) || (prevDirection + 2 == direction))
            direction = prevDirection;
        moveSnake(direction);
        refresh();

        if(collision()) {
            clear();
            mvprintw(max_y/2-2, max_x/2-8, "GAME OVER");
            mvprintw(max_y/2, max_x/2-11, "Your score is %d",score);
            refresh();
            sleep(2);
            break;
        }
        prevDirection= direction;

    }

}
