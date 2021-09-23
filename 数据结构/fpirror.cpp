#include<iostream>

typedef struct person
{
    int data;
    struct person *next;
    struct person *perror;
}per,*list_per;




list_per list_init(list_per head,int n)
{
    list_per p,q;
    q = p = head;
    head = (per*)malloc(sizeof(per));
    q = head;
    std::cout << "请输入第1个结点的数据" << std::endl;
    std::cin >> q->data;
    q->perror = NULL;
    q->next = NULL;

    for(int i = 2 ;i <= n; i++)
    {
        p = (per*)malloc(sizeof(per));
        std::cout << "请输入第" << i << "个结点的数据" << std::endl;
        std::cin >> p->data;
        p->perror = q;
        q->next = p;
        q = p;
    }
    head->perror = q;
    q->next = head;
    return head;
}


void pirror_delete(list_per head,int x)
{
    list_per q,p = head;
    while(p->data != x)
    {
        p = p->next;
    }
    q = p->perror;
    q->perror->next = p;
    std::cout << q->data << "被删除" << std::endl;
    free(q);
}

void list_forlist(list_per head)
{
    int i = 0;
    list_per p;
    if(head == NULL)
    printf("没有人员信息\n");
    else
    {
        p = head;
        printf("data:%d\n",p->data);
        while(p->next != head)
        {
            p = p ->next;
            printf("data:%d\n",p->data);
        }
    }
}


int main(void)
{
    list_per head = NULL;
    int nums,n,i;
    std::cout << "请输入成员人数" << std::endl;
    std::cin >> nums;
    head = list_init(head,nums);
    list_forlist(head);
    std::cout << "请输入给定的结点数据" << std::endl;
    std::cin >> n;
    pirror_delete(head,n);
    return 0;
}