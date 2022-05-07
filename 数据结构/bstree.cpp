#include<iostream>

/* 实现一个二叉排序数 */

typedef struct bitNode
{
    int data;
    struct bitNode *lchild,*rchild;
}BitNode,*BitTree;

//插入操作
bool BSTinsert(BitNode *&p,int key)
{
    if(NULL == p) //空数
    {
        p = new BitNode;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return true;
    }
    //二叉排序树中不可已有相同的值
    if(key == p->data)
    {
        return false;
    }
    // 如果key小于当前的数    
    if(key < p->data )
    {
        return BSTinsert(p->lchild,key); // 通过递归来寻找 
    }
    //否则将在左子树中寻找
    return BSTinsert(p->rchild,key);
}

//创建二叉排序数
void createBst(BitNode *&T,int array[],int n)
{
    T =NULL;
    int i;
    for(i = 0;i < n;i++)
    {
        if(!BSTinsert(T,array[i]))
        {
            std::cout << i << "创建失败" << std::endl;
        }
    }
}

// 该树的中序遍历会得到顺序的数组
void inorderTrace(BitTree T)
{
    if(T)
    {
        inorderTrace(T->lchild);
        std::cout << T->data << " ";
        inorderTrace(T->rchild);
    }
}

int main()
{
    int a[] = {8,9,4,6,34,57,1,2,0,3};
    BitTree T;
    createBst(T,a,sizeof(a)/sizeof(int));
    inorderTrace(T);
    std::cout << std::endl;
    return 0;
}


