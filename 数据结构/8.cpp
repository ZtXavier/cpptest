#include<iostream>
#include<cctype>

typedef struct list_info
{
    int num;
    struct list_info *next;
}*list,in;

typedef struct nums
{
    int i;
    int len;
    int j;
}n;

list list_init(list head)
{
    int nums;
    list p,s;
    std::cout << "请输入你要创建的的链表长度:" << std::endl;
    std::cin >> nums;
    std::cout << "请输入第" << 1 << "个链表的数据:" << std::endl;
    head = (list)malloc(sizeof(in));
    p = head;
    s = head;
    std::cin >> head->num;
    head->next = NULL;
    for(int i = 1;i < nums;i++)
    {
        p = (list)malloc(sizeof(in));
        std::cout << "请输入第" << i+1 << "个链表的数据:" << std::endl;
        std::cin >> p->num;
        s->next = p;
        s = p;
        p->next = NULL;
    }
    return head;
}


void printlist(list head)
{
    list p,s;
    p = head;
    if(!p)
    {
        std::cout << "不存在该链表" << std::endl;
        return ;
    }
    while(p)
    {
        std::cout << p->num <<" ";
        p = p->next;
    }
    std::cout << std::endl;
    return ;
}


list listoperation(list head1,list head2,n info)
{
    int i = info.i;
    int j = info.j;
    int len = info.len;

    list head,tail,p,s,l,q;                               //头结点特殊处理
    p = head1;
    if(i == 0)
    {
        head = s = head1;
        for(int k = 0;k < len-1;k++)
        {
            s = s->next;
        }
        head1 = s->next;
        s->next = NULL;
    }
    else{
        for(int k = 0;k < i - 1;k++)
        {
            p = p->next;
        }
        s = p->next;
        head = p->next;
        for(int k = 0;k < len-1;k++)
        {
            s = s->next;
        }
        p->next = s->next;
        s->next = NULL;
    }

    l = head2;
    if(j == 0)
    {
        s->next = head2;
        free(head1);
        return head;
    }
    for(int k = 0;k < j-1;k++)
    {
        l = l->next;
    }
    q = l->next;
    l->next = head;
    s->next = q;
    free(head1);
    return head2;
}

int main(void)
{
    list head1,head2,head3;
    n nums;
    std::cout << "请分别输入i,len,j" <<std::endl;
    std::cin >> nums.i;
    std::cin >> nums.len;
    std::cin >> nums.j;

    std::cout << "请输入第一条链表的数据" << std::endl;
    head1 =  list_init(head1);
    printlist(head1);
    std::cout << "请输入第二条链表的数据" << std::endl;
    head2 = list_init(head2);
    printlist(head2);

    head3 = listoperation(head1,head2,nums);
    printlist(head3);
    return 0;
}