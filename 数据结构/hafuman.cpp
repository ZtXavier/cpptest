#include<iostream>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

#define N 53
#define MAX 2*N
typedef struct
{
    char name;
    int weight;
    int parent,Lchild,Rchild;
}HTnode,Haffmantree[MAX+1];

//哈夫曼编码标结构
typedef struct cnode
{
    char bs[N + 1];
    int start;
    char ch;
}hufcode;

hufcode code[N + 1];
Haffmantree tree;        //该树是我们创建好的树

char hufmancode[1024];  //该数组来存放已经编码的二进制编码
char word[1024];
int flag = 0;
//定义全局数组来存放这些字符名称和对应的频度
char ch[] = {'\0',' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
float w[N] = {0};


void my_erro(const char * err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

//建立哈夫曼树(利用加权的最小值来建立最优二叉树)
void creattreehuffman(Haffmantree tree)
{
    int i,j;
    int ch1,ch2;
    int min1,min2;             //找到最小和次小的权值
    for(i = 1;i <= MAX;i++)       //先初始化为零
    {
        tree[i].name = '\0';
        tree[i].parent = 0;
        tree[i].Lchild = 0;
        tree[i].Rchild = 0;
        tree[i].weight = 0;
    }

    for(i = 1;i <= N;i++)       //将子叶全部赋值，包括权值和对应的字母
    {
        tree[i].name = ch[i];
        tree[i].weight = w[i];
    }

    for(i = N+1;i <= MAX;i++)     //从此开始来构造双亲结点
    {
        ch1 = 0;
        ch2 = 0;
        min1 = min2 = 10000;
        for(j = 1;j < i;j++)       //这里将遍历子树来为子树找到双亲结点
        {
            if(tree[j].parent == 0)  //每次找到最小的权值的两个子树并将他们的值赋予给一个双亲结点
            {
                if(tree[j].weight < min1)
                {
                    min2 = min1;
                    min1 = tree[j].weight;
                    ch2 = ch1;
                    ch1 = j;
                }
                else
                {
                    if(tree[j].weight < min2)
                    {
                        min2 = tree[j].weight;
                        ch2 = j;
                    }
                }
            }
        }
            tree[ch1].parent = i;
            tree[ch2].parent = i;
            tree[i].Lchild = ch1;
            tree[i].Rchild = ch2;
            //这一步将最小的权值相加然后赋值给双亲结点
            tree[i].weight = tree[ch1].weight + tree[ch2].weight;
    }
    tree[MAX-1].parent = 0;
}

void creatcodehuffman(hufcode code[],Haffmantree tree)
{
    int i,p,c;
    hufcode buf;
    for(i = 1;i <= N;i++)
    {
        buf.ch = ch[i];
        buf.start = N;    //因为树的最深度为叶子结点的个数
        c = i;
        p = tree[i].parent;
        while(p != 0)
        {
            buf.start--;
            if(tree[p].Lchild == c)
            {
                buf.bs[buf.start] = '0';
            }
            else
            {
                buf.bs[buf.start] = '1';
            }
            c = p;
            p = tree[p].parent;
        }
        code[i] = buf;
    }
}
//编码功能 需要优化从文件中获取字符
void writecodehuffman(hufcode code[],Haffmantree tree)
{
    int n = 0;
    int len = 0;
    len = sizeof(word);
    for(int i = 0;i < len;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            if(word[i] == tree[j].name)
            {
                for(int k = code[j].start;k < N;k++)
                {
                    // std::cout << code[j].bs[k];         //验证
                    hufmancode[n] = code[j].bs[k];
                    n++;
                }
            }
        }
    }
    std::cout << "编码成功！编码结果为:\n";
    std::cout << hufmancode << std::endl;
}
//译码部分
void transcodehuffman(hufcode code[],Haffmantree tree,char s[])
{
    int i;
    char *q = NULL;
    i = MAX-1;                   //将i初始化为root结点
    q = s;
    while(*q != '\0')
    {
        if(*q == '0')              //如果是零则走左子树反之走右子树
        {
            i = tree[i].Lchild;
        }
        if(*q =='1')
        {
            i = tree[i].Rchild;
        }
        if((tree[i].Lchild == 0)&&(tree[i].Rchild == 0))
        {
            std::cout << code[i].ch;
            i = MAX -1;
        }
        q++;
    }
    std::cout << std::endl;
}

void printtree(Haffmantree tree)
{
    std::cout << "根据字符的使用概率所建立的树为:\n";
    printf("\t节点序号\t字符名称\t字符频率\t双亲节点\t左孩子\t   右孩子\n");
    for(int i = 1;i < MAX;i++)
    {
        printf("\t %d \t\t %c",i,tree[i].name);
        printf("\t\t%d\t\t%d\t\t%d\t\t%d\n",tree[i].weight,tree[i].parent,tree[i].Lchild,tree[i].Rchild);
    }
}

void printcode(hufcode code[])
{
    printf("哈夫曼树的叶子节点编码为:\n");
    printf("\t字符序号\t字符名称\t字符编码\n");
    for(int i = 1;i <= N;i++)
    {
        printf("\t%d\t%c\t",i,code[i].ch);
        for(int j = code[i].start;j < N;j++)
        {
            printf("%c",code[i].bs[j]);
        }
        printf("\n");
    }
}

void get_weight()
{
    int num = 0;
    FILE *fp;
    if((fp = fopen("codemake.txt","r")) == NULL)
    {
        printf("打开文件失败1");
        exit(0);
    }
    while(1)
    {
        char ch = fgetc(fp);
        if(ch >= 'A' && ch <= 'Z')
        {
            w[ch - 'A' + 2]  += 1;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
           w[ch - 'a' + 28]  += 1;
        }
        else if(ch == ' ')
        {
            w[1] += 1;
        }
        else if(ch == '\n' || ch == EOF)
        {
            break;
        }
        num++;
    }
    for(int i = 1;i < N;i++)
    {
        w[i] = (1.0*w[i] / num) * 100;
    }
}

void ui_hfm()
{
    while(1)
    {
    printf("\t\t            Welcome to haffman transform app \n");
    printf("\t\t*******************************************************\n");
    printf("\t\t            1.写入需要编码的文件                       \n");
    printf("\t\t            2.读取需要编码的文件                       \n");
    printf("\t\t            3.创建哈夫曼树和哈夫曼编码              \n");
    printf("\t\t            4.打印哈夫曼树                                \n");
    printf("\t\t            5.打印元素的哈夫曼编码                    \n");
    printf("\t\t            6.开始编码                                      \n");
    printf("\t\t            7.开始译码                                      \n");
    printf("\t\t            8.读取已完成译码的文件                    \n");
    printf("\t\t            9.退出程序                                      \n");
    printf("\t\t********************************************************\n");
    int step;
    std::cin >> step;
    switch(step)
    {
        case 1:
                bzero(word,sizeof(word));
                std::cout << "请输入:" << std::endl;
                scanf("%s",word);
                FILE *fp;
                if((fp = fopen("codemake.txt","w")) == NULL)
                {
                    my_erro("openfile",__LINE__);
                    exit(1);
                }
                fprintf(fp,"%s",word);
                std::cout << "正在写入...." << std::endl;
                sleep(2);
                std::cout << "写入成功!!!" << std::endl;
                fclose(fp);
                printf("按任意件继续");
                getchar();
                getchar();
                system("clear");
                break;

        case 2:     
                bzero(word,sizeof(word));
                FILE *fp2;
                if((fp2 = fopen("codemake.txt","r")) == NULL)
                {
                    my_erro("openfile",__LINE__);
                    exit(1);
                }
                fscanf(fp2,"%s",word);
                std::cout << "正在读取...." << std::endl;
                sleep(2);
                std::cout << "读取成功:";
                std::cout <<word<< std::endl;
                fclose(fp2);
                printf("按任意件继续");
                getchar();
                getchar();
                system("clear");
                break;
                
        case 3:  
                flag = 1;
                get_weight();
                creattreehuffman(tree);  
                creatcodehuffman(code,tree);
                break;
        case 4: 
                printtree(tree);
                break;
        case 5:
                printcode(code);
                break;
        case 6: 
                if(flag == 0)
                {
                    std::cout << "请先创建haffman树!\n";
                    printf("按任意件继续");
                    getchar();
                    getchar();
                    system("clear");
                    return;
                }
                writecodehuffman(code,tree);
                printf("按任意键继续");
                getchar();
                getchar();
                system("clear");
                flag = 0;
                break;
        case 8:
                // bzero(hufmancode,sizeof(hufmancode));
                FILE *fp3;
                if((fp3 = fopen("codefile.txt","r")) == NULL)
                {
                    my_erro("openfile",__LINE__);
                    exit(1);
                }
                fscanf(fp3,"%s",hufmancode);
                std::cout << "正在读取...." << std::endl;
                sleep(2);
                std::cout << "读取成功:";
                std::cout << hufmancode << std::endl;
                fclose(fp3);
                printf("codefile文件中代码如下:\n");
                std::cout << hufmancode << std::endl;
                break;
        case 7:
                 int ret;
                printf("哈夫曼编码为：%s\n",hufmancode);
                printf("开始译码...\n");
                sleep(2);
                printf("code文件中译码为: ");
                transcodehuffman(code,tree,hufmancode);
                printf("\n");
                std::cout << "是否将编码写入文件(1.yes 2.no)" << std::endl;
                std::cin >> ret;
                if(ret == 1)
                {
                    FILE *fp1;
                    if((fp1 = fopen("codefile.txt","w")) == NULL)
                    {
                        my_erro("打开文件失败\n",__LINE__);
                        exit(0);
                    }
                    fprintf(fp1,"文件编码为:%s",hufmancode);
                    fclose(fp1);
                    printf("写入成功! 按任意件继续...\n");
                    getchar();
                    getchar();
                    system("clear");
                }
                printf("按任意件继续...\n");
                getchar();
                system("clear");
                break;
        default:   
                 exit(0);
    }
    }
}

int main()
{
    while(1)
    {
        ui_hfm();
    }
    return 0;
}

