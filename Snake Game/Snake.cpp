#include "Snake.h"

//Initialization of the variables
Snake :: Snake(coord pos, int speed, int w, int h)
{
    this->pos = pos;
    this->speed = speed;
    length = 1;
    direction = 'r';
    this->h = h;
    this->w = w;

    body.push_back(pos);
}

//Changes the direction of the snake
void Snake :: changeDir(char dir)
{
    direction = dir;
}

vector <coord> Snake :: getBody()
{
    return body;
}

//To move the snake in a direction
void Snake :: moveSnake()
{
    switch(direction)
    {
        case 'u':
            pos.y -= speed;
            break;
        
        case 'd':
            pos.y += speed;
            break;
        
        case 'l':
            pos.x -= speed;
            break;
        
        case 'r':
            pos.x += speed;
            break;
    }

    body.push_back(pos);

    if(body.size() > length)
        body.erase(body.begin());
}

//Get the current position of the snake
coord Snake :: getPos()
{
    return pos;
}

bool Snake :: eaten(coord foodPos)
{
    if(foodPos.x == pos.x && foodPos.y == pos.y)
        return true;
    else
        return false;
}

void Snake :: grow()
{
    length++;
}

bool Snake :: collided()
{
    if(pos.x < 1 || pos.x > w - 2)
        return true;
    else if(pos.y < 1 || pos.y > h - 2)
        return true;

    return false;
}