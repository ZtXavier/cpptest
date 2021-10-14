#include<iostream>
#include<stack>
#include<ctime>
#include<random>


//找到迷宫的所有路径
typedef struct position
{
    int x;
    int y;
    int stp;  //步数
    int lj;   //用来表示路径
}pos;

int my_next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int chessboard[12][12];
int book[12][12];


void my_init(int x,int y)
{
    std::default_random_engine e(time(0));                //这里改用为c11的随机数引擎，而每次要生成随机数的话需要引用time函数来计算每次系统调用的时间
    std::uniform_int_distribution<unsigned> u(1,10);      //这里来进行随机数范围的控制

    for(int i = 0;i < 12;i++)
    {
        if(i == 0 || i == 11)
        {
            for(int j = 0;j < 12;j++)
            {
                chessboard[i][j] = 1;
            }
        }
        else
        {
            chessboard[i][0] = 1;
            chessboard[i][11] = 1;
        }
    }
    for(int i = 0;i < 20;i++)
    {
        chessboard[u(e)][u(e)] = 1;
    }
    chessboard[x][y] = -1;  //出口值
    chessboard[1][1] = 5;   //初始化的值
}

int my_check(int a,int b)
{
    if(a < 0 || b < 0 || a > 11 || b > 11)
    {
        return 0;
    }
    return 1;
}


void my_print()
{
    for(int i = 0;i < 12;i++)
    {
        for(int j = 0;j < 12;j++)
        {
            std::cout << chessboard[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}