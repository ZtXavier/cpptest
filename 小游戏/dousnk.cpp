#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
#include<termio.h>
#include<cstdlib>
#include<sys/select.h>
#include<ctime>
#include<pthread.h>
#include<random>


#define FOOD_   '@'
#define SNAKE_  '#'
#define WEIGHT_ 41
#define HEIGHT_ 41
#define WALL_  '*'


class snake
{
    public:
        snake();
        void init_food();
        void get_move();
        void socre_print();
    private:
        int x1,y1;
        char chessbd[WEIGHT_][HEIGHT_];
        int food[2];

};



snake::snake()
{
    for(int i = 0;i < WEIGHT_;i++)
    {
        chessbd[i][0] = WALL_;
        if(i == WEIGHT_ - 1)
        {
            for(int j = 0;j < HEIGHT_;j++)
            {
                chessbd[i][j] = WALL_;
            }
        }
    }

    for(int i = 0;i < HEIGHT_;i++)
    {
         chessbd[0][i] = WALL_;
         if(i == HEIGHT_ - 1)
        {
            for(int j = 0;j < WEIGHT_;j++)
            {
                chessbd[j][i] = WALL_;
            }
        }
    }
    for(int i = 1;i <WEIGHT_-1;i++)
    {
        for(int j = 1;j < HEIGHT_-1;j++)
        {
            chessbd[j][i] = ' ';
        }
    }
}

void snake::socre_print()
{
    flash_food();
    chessbd[food[0]][food[1]] = FOOD_;
    for(int i = 0;i < WEIGHT_;i++)
    {
        for(int j = 0;j < HEIGHT_;j++)
        {
            std::cout << chessbd[i][j] ;
        }
        std::cout << std::endl;
    }
}

void snake::init_food()
{
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(1,40);
    int x,y;
    while((x = u(e)) != food[0] || (y = u(e)) != food[1])
    {
        food[0] = x;
        food[1] = y;
    }
    std::cout << food[0] << "|" << food[1] << std::endl;
}







int main()
{
    snake sk;
    sk.socre_print();
    return 0;
}