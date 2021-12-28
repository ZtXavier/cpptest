#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXVEX 20

typedef struct EdgeNode                   //边节点
{
    int adjvex;                                     //邻接点域 存对应的下一个节点的下标
    int weight;                                     //权值
    struct EdgeNode *next;                   //指向下一个结点的链
}en;

typedef struct VertexNode
{
    int in;                                           //入度
    int data;                                       //数值
    en * firstedge;                               //边表的头指针
}vn,Adjlist[MAXVEX];

typedef struct                                   //该结构体存储的所有的节点和边的数量
{
    Adjlist adjlist;
    int numvertexes,numRdges;
}graph,*graphadjist;

bool TopologicalSort(graphadjist GL)
{
    en * e;
    int i,k,gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(sizeof(int) * GL->numvertexes);            //开辟所有节点的个数的栈
    for(int i = 0;i < GL->numvertexes;i++)
    {
        if(GL->adjlist[i].in == 0)                                                 // 找入度为零的点
        {
            stack[top++] = i;
        }
    }

    while(top !=0 )
    {
        gettop = stack[top--];                                                              //拿到栈顶的值
        printf("%d ->",GL->adjlist[gettop].data);                                     
        count++;                                                                                //统计节点的个数
        for(e = GL->adjlist[gettop].firstedge;e;e=e->next)                          //找到零接表的每个值
        {
            k = e->adjvex;                                                                     //将零接表的入度减一
            if(!(--GL->adjlist[k].in))                                                          //判断是否入度为零
            {
                stack[++top] = k;
            }
        }
    }
    if(count < GL->numvertexes)                                                           //最后如果有环的话count比节点数目小
    {
        return false;
    }
    return true;
}