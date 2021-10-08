#include<iostream>
#include<stack>
#include<random>
#include<vector>
#include<string>
#include<queue>


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
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(1,10);

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

int my_step(int x,int y)
{
    int head,tail;
    head = tail = 0;
    int flag = 0;       //来标记是否到达终点
    int a,b,i = 0;      //作为预备坐标
    pos ps[145];
    ps[head].x = x;
    ps[head].y = y;
    ps[head].stp = 0;
    ps[head].lj = 0;
    book[ps[head].x][ps[head].y] = 1;   //标记该点为1
    tail++;                             //确保进入循环
    while(head < tail)      //队列不为空时循环
    {
        for(i = 0;i < 4;i++)
        {
            a = ps[head].x + my_next[i][0];
            b = ps[head].y + my_next[i][1];
            if(my_check(a,b) && chessboard[a][b] == -1)
            {
                std::cout << "成功找到出口" << std::endl;
                return ps[tail - 1].stp;
            }
            else if(my_check(a,b) && chessboard[a][b] == 0 && book[a][b] == 0)
            {
                chessboard[a][b] = 5;
                book[a][b] = 1;
                ps[tail].x = a;
                ps[tail].y = b;
                ps[tail].stp = ps[head].stp + 1;
                tail++;
            }
        }
        head++;   //每当一个点扩展完后才能对下一个(head++)进行扩展
    }
    std::cout << "没有出口可走" << std::endl;
    return 0;
}


int main()
{
    int x,y;
    int res;
    std::cin >> x >> y;
    my_init(x,y);
    my_print();
    res = my_step(1,1);
    std::cout << "最短路径为：" << res << std::endl;
    my_print();
    return 0;
}