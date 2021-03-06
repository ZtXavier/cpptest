#include<iostream>
#include<stack>
#include<string>
#include<fcntl.h>

#define N 27
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

char hufmancode[1000];  //该数组来存放已经编码的二进制编码

//定义全局数组来存放这些字符名称和对应的频度
char ch[] = {'\0',' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
float w[] = {0,186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};

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
    std::string file;
    std::cout << "请输入字符串:" << std::endl;
    std::cin >> file;
    std::cout << std::endl;
    for(int i = 0;i < file.size();i++)
    {
        for(int j = 1;j <= N;j++)
        {
            if(file[i] == tree[j].name)
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

// void printtree(Haffmantree tree)
// {
//     std::cout << "根据字符的使用概率所建立的树为:\n";
//     printf("\t字符序号\t字符名称\t字符频率\t双亲位置\t左孩子\t右孩子\n");
//     for(int i = 1;i < MAX;i++)
//     {
//         printf("\t %d \t %c \t",i,tree[i].name);
//         printf("%d\t%d\t%d\t%d\n",tree[i].weight,tree[i].parent,tree[i].Lchild,tree[i].Rchild);
//     }
// }

void printcode(hufcode code[])
{
    // printf("根据哈夫曼树对字符建立的编码为:\n");
    // printf("\t字符序号\t字符名称\t字符编码\n");
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

int main()
{
    FILE *fp1,*fp2;
    char buffer[1000];
    creattreehuffman(tree);
    // printtree(tree);
    creatcodehuffman(code,tree);
    printcode(code);
    writecodehuffman(code,tree);
    if((fp1 = fopen("codefile.txt","w")) == NULL)
    {
        printf("打开文件失败\n");
        exit(0);
    }
    fprintf(fp1,"文件编码为:%s",hufmancode);
    // printf("codefile文件中代码如下:\n");
    printf("哈夫曼编码为：%s\n",hufmancode);
    printf("code文件中译码为: ");
    transcodehuffman(code,tree,hufmancode);
    printf("\n");
    return 0;
}

