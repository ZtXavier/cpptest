#include<iostream>
#include<stack>

typedef struct position
{
    int x;
    int y;
    int stp;
}pos;

//定义一个棋盘,全局变量默认值为0
int chessboard[5][5];
//定义由水平线开始顺时针方向来进行旋转走八字
int my_next[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
//定义一个计数器,来标记棋盘上的数
int num = 1;

void my_print()
{
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            std::cout << chessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n" << std::endl;
}

int My_check(int a,int b)
{
    if(a < 0 || a > 4 || b < 0 || b > 4)
    {
        return 0;
    }
    return 1;
}

void my_horse(int x,int y)
{
    int a,b;
    for(int i = 0;i < 8;i++)
    {
        a = x + my_next[i][0];
        b = y + my_next[i][1];
        if(My_check(a,b) && chessboard[a][b] == 0)
        {
            chessboard[a][b] = (++num);
            if(num == 25)
            {
                my_print();
            }
            else
            {
                my_horse(a,b);
            }
            chessboard[a][b] = 0;
            num--;
        }
    }
}


int main()
{
    int x,y;
    my_print();
    std::cout << "请选择一个坐标: ";
    std::cin >> x >> y;
    chessboard[x][y] = 1;
    my_horse(x,y);
    return 0;
}
