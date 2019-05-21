#include "snakepart.h"

snakePart::snakePart(int x, int y)
{
    this->x = x;
    this->y = y;
}

char snakePart::getCh() const {
    return ch;
}

int snakePart::getX() const {
    return x;
}

int snakePart::getY() const {
    return y;
}
