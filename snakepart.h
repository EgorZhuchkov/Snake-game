#ifndef SNAKEPART_H
#define SNAKEPART_H


class snakePart
{
    int x;
    int y;
    const char ch = 'O';
public:
    snakePart(int x, int y);
    int getY() const;
    int getX() const;
    char getCh() const;
};

#endif // SNAKEPART_H
