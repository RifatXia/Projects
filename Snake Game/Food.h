#ifndef FOOD_H
#define FOOD_H

#include "Snake.h"
#include <cstdlib>

class Food
{
    private:
        coord pos;
        int w, h;

    public:
        Food(int, int);
        void genFood();
        coord getPos();
};
#endif // !FOOD_H