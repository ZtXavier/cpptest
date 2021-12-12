#include<stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct Sqlist{
    int length;
    int *array;
}sqlist;


sqlist * list_init(sqlist *l)
{
    l = (sqlist *)malloc(sizeof(sqlist));
    printf("请输入数据个数:\n");
    scanf("%d",&l->length);
    l->array = (int*)malloc(sizeof(int)*(l->length+1));
    printf("请输入数据元素:\n");
    for(int i = 1;i <= l->length;i++)
    {
        scanf("%d",&l->array[i]);
    }
    return l;
}

void Swap(sqlist *l,int a,int b)
{
    int tmp;
    tmp = l->array[a];
    l->array[a] = l->array[b];
    l->array[b] = tmp;
}

int Partition(sqlist *l,int low,int high)
{
    int pivotkey;
    pivotkey = l->array[low];          //选择一个岗哨最为比较基准
    while(low < high)
    {
        while(low < high && l->array[high] >= pivotkey)      //如果high所指的元素大于岗哨，则指针向前偏移
            high--;
        Swap(l,low,high);
        while(low < high && l->array[low] <= pivotkey)
            low++;
        Swap(l,low,high);
    }
    return low;
}

void Qsort(sqlist *l,int low,int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(l,low,high);

        Qsort(l,low,pivot - 1);
        Qsort(l,pivot + 1,high);
    }
}


void QuickSort(sqlist *l)
{
    Qsort(l,1,l->length);
}


int main()
{
    sqlist *list;
    list = list_init(list);
    QuickSort(list);
    for(int i = 1;i <= list->length;i++)
    {
        printf("%d ",list->array[i]);
    }
    return 0;
}