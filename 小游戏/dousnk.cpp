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
#include<stdlib.h>
#include<stdio.h>



#define FOOD_   '@'
#define SNAKE_BODY '.'
#define SNAKE_HEAD  '#'
#define WEIGHT_ 41
#define HEIGHT_ 41
#define WALL_  '*'
#define score 23

// pthread_mutex_t mtx;
class snake
{
    public:
        snake();
        void print_ui();
        void init_food();
        void Deletesnake(int *s);
        int get_move(int *s,int x,int y);
        void judge_win(int *s);
        void initRandSanke(int *s);
        int Score;
    private:
        char chessbd[WEIGHT_][HEIGHT_];
        int food[2];
};



 snake::snake()
{
    Score = 0;
    init_food();
    chessbd[food[0]][food[1]] = FOOD_;
}

//初始化食物
void snake::init_food()
{
    srand((unsigned)time(NULL));
    int x,y;
    x = 1 + rand() % (WEIGHT_ - 2);
    y = 1 + rand() % (HEIGHT_ - 2);
    while((x != food[0]) || (y != food[1]))
    {
        food[0] = x;
        food[1] = y;
    }
    std::cout << "x = " << food[0] << "|" << "y = " << food[1] << std::endl;
}

void snake::initRandSanke(int *s)
{
    srand((unsigned)time(0));
    int x = 2 + rand() % (WEIGHT_ - 3);
    int y = 2 + rand() % (HEIGHT_ - 6);
    // *(snake + 1) = y;         //用一个指针所指向的数组来存储蛇身
    // *(snake) = x;
    int i = 0;
    while(i < 6)
    {                     //初始化贪吃蛇
        s[i] = x;
        s[i + 1] = y;
        i += 2;
    }
    food[0] = 1 + rand() % (WEIGHT_ - 2);
    food[1] = 1 + rand() % (HEIGHT_ - 2);
}

void snake::print_ui()
{
     std::cout <<"\t---->" <<    "贪吃蛇" << "<----" << std::endl;
    std::cout << "\t    " <<    "得分" <<  Score <<"\t    " << std::endl;
    std::cout << "\t    " <<    "蛇的长度()"  << Score + 3 << "\t    "<< std::endl;
    for(int i = 0;i < WEIGHT_;i++)          //根据棋盘存储的数据来打印对应的信息
    {
        for(int j = 0;j < HEIGHT_;j++)
        {
            if(i == 0 || i == WEIGHT_ - 1 || j == 0 || j == HEIGHT_ - 1)
            {
                std::cout << WALL_ << "";
            }
            else if(chessbd[i][j] == 1)           //如果是1则打印蛇头
            {
                std::cout << SNAKE_HEAD << "";
            }
            else if(chessbd[i][j] == 2)           //如果是2则打印蛇身
            {
                std::cout  << SNAKE_BODY <<"";
            }
            else if(chessbd[i][j] == 3)
            {
                std::cout << FOOD_ << "";
            }
            else if(chessbd[i][j] == 0)
            {
                std::cout << " " << "";
            }
        }
        std::cout << std::endl;
    }
}

void snake::judge_win(int *s)         //刷新操作
{
    for(int i = 1;i < WEIGHT_;i++)
    {
        for(int j = 1;j < HEIGHT_;j++)
        {
            chessbd[i][j] = 0;
        }
    }
    chessbd[s[0]][s[1]] = 1;                               //蛇头的坐标处标志为1
    for(int i = 2;s[i] != 0 && s[i+1] != 0;i += 2)
    {
        if(i/2 + 3 < score)
        {
            chessbd[s[i]][s[i+1]] = 2 ;                     //蛇身处标记为2
        }
        else
        {
            system("clear");
            std::cout << "Congradulations !!!" << std::endl;
            exit(0); 
        }
    }
    chessbd[food[0]][food[1]] = 3;
}

int snake::get_move(int *s,int x,int y)
{
    if(x == 0 || x == WEIGHT_ - 1 || y == 0 || y == HEIGHT_ - 1)
    {
        std::cout << "Game over" << std::endl;
        std::cout << "Don`t touch wall" << std::endl;
        exit(0);
    }
    else if(chessbd[x][y] == 2)          //如果碰到自己也算失败
    {
        std::cout << "Game over" << std::endl;
        std::cout << "Don`t touch yourself" << std::endl;
        exit(0);
    }
    int p;
    for(p = 0;s[p] != 0 && s[p+1] != 0;p += 2);
    for(p += 2;p != 0;p -= 2)                                  // 移动交换 x与x，y与y交换，并且将空的位置调回到蛇头
    {
        s[p - 2] = s[p - 2] ^ s[p];
        s[p] = s[p - 2] ^ s[p];
        s[p - 2] = s[p - 2] ^ s[p];

        s[p - 3] = s[p - 3] ^ s[p - 1];
        s[p - 1] = s[p - 3] ^ s[p - 1];
        s[p - 3] = s[p - 3] ^ s[p - 1];
    }
    s[0] = x;         //设置蛇头的新坐标
    s[1] = y;
    if(x == food[0] && y == food[1])        // 如果吃到食物就重新生成一个食物
    {
        init_food();
        return 1;
    }
    return 0;
}

void snake::Deletesnake(int * s)
{
    int i;
    for(i = 0;s[i+2] != 0 && s[i+3] != 0;i += 2);
    std::cout << "x = " << *s <<" y = "<< *(s+1) << std::endl;        //找到蛇尾的坐标
    chessbd[s[i]][s[i+1]] = 0;                                                    //设置为空白区域
    s[i+1] = s[i] = 0;                                                                //将存储蛇的空间也设置为0
}


void Welcome()
{					
    std::cout << "welcome to snake game" << std::endl;		
	while(getchar() != '\n')
		continue;
	// system("read -n");
	system("clear");
}

void * getch(void *argv)
{
    int *arg = (int*)argv;
    *arg = getchar();
    while(getchar() != '\n')
    {
        continue;
    }
    if(*arg != 'a' || *arg != 's' || *arg != 'd' || *arg != 'w')
        arg = NULL;
    return NULL;
}

int main()
{
    int *a = new int;          //我们在main函数中申请一个内存来保存键盘输入的值
    *a = 'a';
    int first_step;
    first_step = 'a';
    int *s = new int[score * 10]{0};
    pthread_t pth1;
    snake sk;
    sk.initRandSanke(s);
    sk.init_food();
    sk.judge_win(s);
    Welcome();
    while(1)
    {
        int i = 0;
        system("clear");
        sk.print_ui();
        pthread_create(&pth1,NULL,getch,a);
        if(a == NULL)
            *a = first_step;
        sleep(1);
        // usleep(100000);
        if(*a == 'a' && first_step != 'd' || *a == 'd' && first_step != 'a' ||
			*a == 'w' && first_step != 's' || *a == 's' && first_step != 'w' || *a == 'q')
            {
                first_step = *a;
                switch(*a)
                {
                case 'a': if(sk.get_move(s,s[0],s[1]-1))
                            i++; break;
				case 'd':  if(sk.get_move(s,s[0],s[1]+1))
                            i++; break;
				case 'w': if(sk.get_move(s,s[0]-1,s[1]))
                            i++; break;
				case 's':  if(sk.get_move(s,s[0]+1,s[1]))
                            i++; break;
				default:exit(0);
                }
                if(i == 0)
                    sk.Deletesnake(s);
                else
                {
                    sk.Score++;
                    sk.init_food();
                }
                sk.judge_win(s);
            }
    }
    delete a;
    delete [] s;
    return 0;
}