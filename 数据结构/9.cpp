#include<iostream>
#include<cctype>

typedef struct list_info
{
    int num;
    struct list_info *next;
}*list,in;

list list_init(list head)
{
    int num;
    list p,s;
    std::cout << "请输入数据的数量" << std::endl;
    std::cin >> num;
    head = (list)malloc(sizeof(in));
    std::cout << "请输入第1个数据信息" << std::endl;
    std::cin >>head->num;
    head->next = NULL;
    p = s = head;
    for(int i = 2;i <= num;i++)
    {
        p = (list)malloc(sizeof(in));
        std::cout << "请输入第" << i << "个数据信息" << std::endl;
        std::cin >> p->num;
        s->next = p;
        s = p;
        p->next = NULL;
    }
    return head;
}

void printlist(list head)
{
    list p = head;
    while(p != NULL)
    {
        std::cout << p->num << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int listnums(list head)
{
    int nums = 0;
    list p;
    p = head;
    while(p != NULL)
    {
        p = p->next;
        nums++;
    }
    return nums;
}

list list_operation(list head1,list head2)
{
    int m,n;
    list head3,p,s,q,l,k;
    list tmp;
    head3 = (list)malloc(sizeof(in));
    p = s = head3;
    q = head1;
    l = head2;
    head3->next = NULL;
    m = listnums(head1);
    n = listnums(head2);
    if(m <=  n)
    {
        tmp = q;
        q = l;
        l = tmp;
    }
        while(q != NULL && l != NULL)
        {
            p = (list)malloc(sizeof(in));
            p ->num = q ->num;
            s->next = p;
            s = p;
            p = (list)malloc(sizeof(in));
            p->num = l->num;
            s->next = p;
            s = p;
            p->next = NULL;
            k = q;
            q = q->next;
            l = l->next;
        }
        p->next = q;
        k->next = NULL;
        free(head1);
        free(head2);
    return head3->next;
}

int main(void)
{
    list head1,head2,head3;
    head1 = list_init(head1);
    printlist(head1);
    head2 = list_init(head2);
    printlist(head2);
    head3 = list_operation(head1,head2);
    std::cout << "结果为: ";
    printlist(head3);
    std::cout << std::endl;
    return 0;
}