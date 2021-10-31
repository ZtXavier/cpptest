#include<iostream>



//堆排序的公式  i:代表深度 ; parent = (i-1)/2 ;child = (2*i +1) 或(2*i+2)


void Swap(int tree[],int max,int i)
{
    int t = tree[max];
    tree[max] = tree[i];
    tree[i] = t;
}

void heapify(int tree[],int n,int i)//n 表示有n个结点，i表示对第i个结点进行操作
{
    if((2*i+ 1) >= n || (2*i + 2) >= n)
    {
        return ;
    }
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int max = i;
    if(c1 < n && tree[c1] > tree[max])  //两个判断分别表示不能超过最大结点以及对于子树间的交换
    {
        max = c1;
    }
    if(c2 < n && tree[c2] > tree[max])
    {
        max = c2;
    }
    if(max != i)
    {
        Swap(tree,max,i);
        heapify(tree,n,max);
    }

}

void build_heapify(int tree[],int n)
{
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;   //根据公式计算
    for(int i = parent;i >= 0;i--)
    {
        heapify(tree,n,i);
    }
}


int main()
{
    int arr[] = {4,2,5,7,6};
    int n = 5;
    build_heapify(arr,n);
    for(int i = 0;i < n;i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}