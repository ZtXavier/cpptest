#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<time.h>

typedef struct Position
{
    int y;
    int x;
    int p;   //方向
    int stp; //下一步权值
    int flag; //用来判断是否有路可走
}position;

//定义一个棋盘,全局变量默认值为0
int chessboard[8][8];
//定义由水平线开始顺时针方向来进行旋转走八字
int my_next[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
//定义一个计数器
int num = 0;
//定义一个位置的栈
std::stack<position> hornum;

bool my_cmp(position &a,position &b)
{
    return a.stp < b.stp;
}



int My_check(int a,int b)
{
    if(a < 0 || a > 7 || b < 0 || b > 7)
    {
        return 0;
    }
    return 1;
}

int tp_num(int a,int b)
{
    int res = 0;
    int x,y;
    for(int i = 0;i < 8;i++)
    {
        x = a + my_next[i][0];
        y = b + my_next[i][1];
        if(My_check(x,y) && chessboard[x][y] == 0)
        {
            res++;
        }
    }
    return res;
}

void my_horse_min(int x,int y)     //找到最小权值
{
    int tp;  //记录权值
    position ps;
    ps.x = x;
    ps.y = y;
    ps.p = 0;
    chessboard[x][y] = (++num);
    int a,b; //定义a和b来进行位置的赋值和判断
    while(num < 64) //整个棋盘全部走完后结束
    {
        int qz_min = 8; //来用贪心算法来找到权值最小的点，先初始化为最大值8
        int qx,qy,qp;   //来记录最小的点的信息
        for(int i = 0;i < 8;i++)
        {
            a = ps.x + my_next[i][0];  //枚举每一步将其赋值到判断变量中
            b = ps.y + my_next[i][1];
            if(My_check(a,b) && chessboard[a][b] == 0)
            {
                tp = tp_num(a,b);
                if(tp < qz_min)    //找到接下来要走的八个权值中的最小值
                {
                    qz_min = tp;
                    qx = a;
                    qy = b;
                    qp = i;        //记录方向
                }
            }
        }
        chessboard[qx][qy] = (++num);
        ps.stp = qp;
        hornum.push(ps);
        ps.x = qx;
        ps.y = qy;
    }
}

void my_horse_normal(int x,int y)
{
    position ps;
    position ps1[8];
    ps.x = x;
    ps.y = y;
    ps.p = 0;
    chessboard[x][y] = (++num);
    for(int i = 0;i < 8;i++)
    {
        ps1[i].x = 0;
        ps1[i].y = 0;
        ps1[i].p = 0;
        ps1[i].flag = 0;
        ps1[i].stp = 0;
    }
    int a,b;
    int flag = 0;
    while(num < 64)
    {
        int k = 0;
        for(int i = 0;i < 8;i++)
        {
            a = ps.x + my_next[i][0];
            b = ps.y + my_next[i][1];
            if(My_check(a,b) && chessboard[a][b] == 0) //找到能走的点位
            {
                int tp = tp_num(a,b); //下一步的权值计算
                ps1[k].x = a;
                ps1[k].y = b;
                ps1[k].stp = tp;
                ps1[k].p = i;          //方向
                k++;
            }
        }
        std::sort(ps1,ps1+k,my_cmp);
        for(int i = 0;i < k;i++)
        {
            ps1[i].flag = i;
        }

        if(k > 0 && flag < k)  //说明有可走的路
        {
            chessboard[ps1[flag].x][ps1[flag].y] = (++num);
            ps.stp = ps1[flag].stp;    //权值赋值
            ps.flag = ps1[flag].flag;
            ps.p = ps1[flag].p;
            //将要走的路的信息记录在当前位置的结构体中
            hornum.push(ps);
            //将压栈完后的信息更新
            ps.flag = 0;
            ps.p = 0;
            ps.stp = 0;
            //将所走的坐标更新
            ps.x = ps1[flag].x;
            ps.y = ps1[flag].y;
            //标记位来初始化，表示该位成功走后下一次依旧从第一位(最小权值)开始走
            flag = 0;
        }
        else  //回溯
        {
            num--;
            chessboard[ps.x][ps.y] = 0;
            position hs = hornum.top();
            hornum.pop();
            ps.x = hs.x;
            ps.y = hs.y;
            flag = hs.flag;
            flag++;
        }
    }
}


void my_print()
{
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            std::cout << chessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    int x,y;
    int i = 1;
    my_print();
    std::cout << "请选择一个坐标: ";
    std::cin >> x >> y;
    // my_horse_min(x,y);
    clock_t start = clock();
    my_horse_normal(x,y);
    clock_t finish = clock();
    double runtime = (double)(finish - start)/CLOCKS_PER_SEC;
    std::cout << "run time: " << runtime << std::endl;
    my_print();
    while(!hornum.empty())
    {
        position p;
        p = hornum.top();
        std::cout << "(" << p.x << "," << p.y << ")" << " ";
        if(i%8 == 0)
        std::cout << std::endl;
        hornum.pop();
        i++;
    }
    return 0;
}
