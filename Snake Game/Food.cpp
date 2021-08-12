#include "Food.h"

//Initializing the max points of the food
Food :: Food(int w, int h)
{
    this->w = w;
    this->h = h;
    genFood();
}

//Randomly generating a coordinate and setting it as the current position of the food
void Food :: genFood()
{
    pos.x = rand() % w + 1;
    pos.y = rand() % h + 1;
}

//Getting the current position of the food item
coord Food :: getPos()
{
    return pos;
}
