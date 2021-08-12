#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
using namespace std;

struct coord
{
    int x;
    int y;
};

class Snake
{
    private:
        coord pos;
        int speed;
        char direction;
        int h, w;
        vector <coord> body;

    public:
        int length;
        Snake(coord, int, int, int);
        void changeDir(char dir);
        void moveSnake();
        coord getPos();
        bool eaten(coord foodPos);
        void grow();
        bool collided();
        vector <coord> getBody();
};

#endif // !SNAKE_H