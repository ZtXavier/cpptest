#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<time.h>

using namespace std;

const int S = 16;
const char ChessBoard = ' ';
const char flag1 = 'o';
const char flag2 = 'x';
const int p1 = 1;
const int p2 = 2;
const int com = 0;

typedef struct Position
{
    int row;
    int col;
}P;


class BeginGo
{
    public:
        BeginGo();

        int ChoiceMode();
        void initChessBoard();
        void printChessBoard();
        bool Vectoried(P &p,const int who,const char fg);
        void Compstep(P &p,const char fg);
        void Playerstep(P &p,const int who,const char fg);
        bool JudgeValue(P &p);
        int JudgeWin(P&p,const char fg);
        void Begin();
    
    private:
        char _ChessBoard[S+1][S+1];

};


// 初始化棋盘
BeginGo::BeginGo()
{
    initChessBoard();
}

void BeginGo::initChessBoard()
{
    for(int i = 0;i < S+1;i++)
    {
        for(int j = 0;j < S+1;j++)
        {
            _ChessBoard[i][j] = ChessBoard;
        }
    }
}

void BeginGo::printChessBoard()
{
        printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16\n");
        printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
        for (int i = 1; i < S + 1; ++i)
        {
            printf("%2d ", i);
            printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", _ChessBoard[i][1], _ChessBoard[i][2], _ChessBoard[i][3], _ChessBoard[i][4], _ChessBoard[i][5], _ChessBoard[i][6], _ChessBoard[i][7], _ChessBoard[i][8], _ChessBoard[i][9], _ChessBoard[i][10], _ChessBoard[i][11], _ChessBoard[i][12], _ChessBoard[i][13], _ChessBoard[i][14], _ChessBoard[i][15],_ChessBoard[i][16]);
            printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
        }
        cout << endl;
}

int BeginGo::ChoiceMode()
{
    system("clear");
    int mode;
    initChessBoard();
    printf("\t****************************************************\n");
    printf("\t****************          0.exit         *****************\n");
    printf("\t****************          1.pve         *****************\n");
    printf("\t****************          2.pvp         *****************\n");
    printf("\t****************************************************\n");
    while(1)
    {
        cout << "请选择模式:"<< endl;
        cin >> mode;
        if(mode == 0)
        {
            exit(0);
        }
        if(mode == 1 || mode == 2)
        {
            break;
        }
        else
        {
            cout << "非法输入，请重新输入!" << endl;
        }
    }
    return mode;
}

void BeginGo::Compstep(P &p ,const char fg)
{
    printChessBoard();
    int x = 0;
    int y = 0;
    while(1)
    {
        x = (rand() % S) + 1;
        srand((unsigned int)time(NULL));
        y = (rand() % S) + 1;
        srand((unsigned int)time(NULL));
        if(_ChessBoard[x][y] == ChessBoard)
        {
            break;
        }
    }
    p.row = x;
    p.col = y;
    _ChessBoard[p.row][p.col] = fg;
}

bool BeginGo::JudgeValue(P &p)
{
    if(p.row > 0 && p.row <= S && p.col <= S && p.col > 0)
    {
        if(_ChessBoard[p.row][p.col] == ChessBoard)
        {
            return true;
        }
    }
    return false;
}

void BeginGo::Playerstep(P &p,int who ,const char fg)
{
    printChessBoard();
    while(1)
    {
        printf("请玩家%d输入坐标:",who);
        cin >> p.row >> p.col;
        if(JudgeValue(p))
        {
            break;
        }
        cout << "输入错误，请重新输入" << endl; 
    }
    _ChessBoard[p.row][p.col] = fg;
}

void BeginGo::Begin()
{
    P player1;
    P player2;
    while(1)
    {
        int mode = ChoiceMode();
        while(1)
        {
            if(mode == 1) // 电脑vs玩家
            {
                Compstep(player1,flag1);
                if(Vectoried(player1,com,flag1))
                {
                    break;
                }
                Playerstep(player2,p2,flag2);
                if(Vectoried(player2,p2,flag2))
                {
                    break;
                }
            }
            // pvp
            else
            {
                Playerstep(player1,p1,flag1);
                if(Vectoried(player1,p1,flag1))
                {
                    break;
                }
                Playerstep(player2,p2,flag2);
                if(Vectoried(player2,p2,flag2))
                {
                    break;
                }
            }
        }
        cout << "play again ?" << endl;
        cout << "yes or no" << endl;
        string choice = "yes";
        cin >> choice;
        if(choice == "no")
        {
            break;
        }
    }
}

int BeginGo::JudgeWin(P &p,const char fg)
{
    int begin = 0;
    int end = 0;

    begin = (p.col - 4) > 0 ? (p.col - 4) : 1;
    end = (p.col + 4) > S ? S : (p.col + 4);
    for(int i = p.row,j = begin;j + 4 <= end;++j)
    {
        if(_ChessBoard[i][j] == fg && _ChessBoard[i][j + 1] == fg && _ChessBoard[i][j + 2] == fg && _ChessBoard[i][j + 3] == fg && _ChessBoard[i][j + 4] == fg)
        {
            return 1;
        }
    }

    begin = (p.row - 4) > 0 ? (p.row - 4) : 1;
    end = (p.row + 4) > S ? S : (p.row + 4);
    for(int i = begin,j = p.col;i + 4 <= end;++i)
    {
        if(_ChessBoard[i][j] == fg && _ChessBoard[i + 1][j] == fg && _ChessBoard[i + 2][j] == fg && _ChessBoard[i + 3][j] == fg && _ChessBoard[i + 4][j] == fg)
        {
            return 1;
        }
    }

    int len = 0;
    int start = 0;
    int finish = 0;

    len = p.row > p.col ? p.col - 1 : p.row - 1;
    if(len > 4)
    {
        len = 4;
    }
    begin = p.row - len;
    start = p.col - len;

    len = p.row > p.col ? S - p.row : S - p.col;  
    if(len > 4)
    {
        len = 4;
    }
    end = p.row + len;          // 横坐标结束位置
    finish = p.col + len;         // 纵坐标结束位置

    for(int i = begin,j = start;(i + 4 <= end) && (j + 4 <= finish);i++,j++)
    {
        if(_ChessBoard[i][j] == fg && _ChessBoard[i + 1][j + 1] == fg && _ChessBoard[i + 2][j + 2] == fg &&  _ChessBoard[i + 3][j + 3] == fg &&  _ChessBoard[i + 4][j + 4] == fg)
        {
            return 1;
        }
    }
    
    len = (p.row - 1) > (S - p.col) ? S - p.col : p.row - 1;
    if(len > 4)
    {
        len = 4;
    }
    begin = p.row - len;
    start = p.col + len;
    
    len = (S - p.row) > (p.col - 1) ?  p.col - 1 : S - p.row;
    end = p.row + len;
    finish = p.col - len;

    for(int i = begin,j = start;(i + 4 <= end) && (j - 4 >= finish);++i,--j)
    {
        if(_ChessBoard[i][j] == fg && _ChessBoard[i + 1][j - 1] == fg && _ChessBoard[i + 2][j - 2] == fg && _ChessBoard[i + 3][j - 3] == fg && _ChessBoard[i + 4][j - 4] == fg)
        {
            return 1;
        }
    }

    for(int x = 1;x < S + 1;++x)
    {
        for(int y = 1;y < S + 1;++y)
        {
            if(_ChessBoard[x][y] == ChessBoard)
            {
                return 0;
            }
        }
    }
    return 2; // 合局
}

bool BeginGo::Vectoried(P &p,const int who,const char fg)
{
    int jd = JudgeWin(p,fg);
    if(jd != 0 )        // 无人获胜，游戏继续
    {
        if(jd == 1)
        {
            if(who == com)
            {
                cout << "电脑获胜" << endl;
            }
            else
            {
                cout << "恭喜玩家" << who << "胜利" << endl;
            }
        }
        else
        {
            cout << "和局" << endl;
        }
       return true;
    }
    return false;
}


int main()
{
    BeginGo b;
    b.Begin();
    system("clear");
    return 0;
}