#include <iostream>
#include <cstdlib>
#include <ctime>
//Header to set the c    ursor position
#include <windows.h>
//Header to interact using the console - (console input output)
#include <conio.h>
#include "Snake.cpp"
#include "Food.cpp"
using namespace std;

int width = 50, height = 25, score = 0;

//Making the snake and food object
Snake snake({width/2, height/2}, 1, width, height);
Food food(width, height);
void board()
{
    cout << "Score : " << score << endl;
    coord snakePos = snake.getPos();
    coord foodPos = food.getPos();

    vector <coord> snakeBody = snake.getBody();
    
    for(int i = 0; i < height; i++)
    {   
        for(int j = 0; j < width; j++)
        {
            if(i == 0 || j == 0 || i == height - 1 || j == width - 1)
                cout << "#";
            else if(i == snakePos.y && j == snakePos.x)
                cout << "O";
            else if(i == foodPos.y && j == foodPos.x)
                cout << "X";
            else
            {
                bool isBody = false;
                for(int k = 0; k < snakeBody.size() - 1; k++)
                {
                    if(i == snakeBody[k].y && j == snakeBody[k].x)
                    {
                        cout << "o";
                        isBody = true;
                        break;
                    }
                }

                if(!isBody)
                    cout << " ";
            }
        }
        cout << endl;
    }
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        // freopen("out.txt", "w", stdout);
    #endif

    srand(time(NULL));
    
    bool gameOver = false;
    while(!gameOver)
    {
        board();
        
        //Hitting a keyboard button and changing the direction accordingly
        if(kbhit())
        {
            char c = getch();

            if(c == 'w' || c == 72)
                snake.changeDir('u');
            else if(c == 's' || c == 80)
                snake.changeDir('d');
            else if(c == 'a' || c == 75)
                snake.changeDir('l');
            else if(c == 'd' || c == 77)
                snake.changeDir('r');
        }

        if(snake.eaten(food.getPos()))
        {
            food.genFood();
            snake.grow();
            score++;
        }

        if(snake.collided())
        {
            gameOver = true;
        }

        snake.moveSnake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    cout << "Final Score = " << score << endl;

    return 0;
}
