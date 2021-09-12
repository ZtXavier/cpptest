#include<cctype>
#include<iostream>


typedef struct info
{
    int item;
    int power;
    struct info *next;
}nums,*list_nums;


list_nums list_init(list_nums head)                       //创建有头结点的链表
{
    int num;
    list_nums p,s;
    head = (list_nums)malloc(sizeof(nums));
    head->next = NULL;
    p = head;
    std::cout << "请输入你要创建的项数" << std::endl;
    std::cin >> num;
    for(int i = 0;i < num;i++)
    {
        s = (list_nums)malloc(sizeof(nums));
        std::cout << "请输入第" << i << "项的项数" << std::endl;
        std::cin >> s->item;
        std::cout << "请输入第" << i << "项的指数" << std::endl;
        std::cin >> s->power;
        p->next = s;
        p = s;
        s->next = NULL;
    }
    return head;
}

int printlist(list_nums head)
{
    int flag = 1;
    list_nums p;
    p = head->next;
    if(!p)
    {
        std::cout << '0' << std::endl;
        return 0;
    }

    while(p)
    {
        if(p->item == 0)
        {
            p = p->next;
            flag++;
            continue;
        }

        if(flag != 1 && p->item > 0)
        {
            if(p->item == 1)
            {
                if(p->power != 1)
                printf("+X^%d",p->power);
                else
                printf("+X");
            }
            else
            {
                if(p->power != 1)
                printf("+%dX^%d",p->item,p->power);
                else
                printf("+%dX",p->item);
            }

        }
        else if(flag != 1 && p->item < 0)
        {
        if(p->item == 1)
            {
                if(p->power != 1)
                printf("X^%d",p->power);
                else
                printf("X");
            }
            else
            {
                if(p->power != 1)
                printf("%dX^%d",p->item,p->power);
                else
                printf("%dX",p->item);
            }
        }
        else
        {
            if(p->power == 0)
            {
                printf("%d",p->item);
            }
            else
            {
                if(p->item == -1)
                {
                    if(p->power != 1)
                    printf("-X^%d",p->power);
                    else
                    printf("-X",p->item);
                }
                else if(p->item == 1)
                {
                    if(p->power != 1)
                    printf("X^%d",p->power);
                    else
                    printf("X",p->item);
                }
                else
                {
                    if(p->power != 1)
                    printf("%dX^%d",p->item,p->power);
                    else
                    printf("%dX",p->item);
                }
            }
        }
        p = p->next;
        flag++;
    }
    return 0;
}

int list_forlist(list_nums head)
{
    list_nums p;
    p = head;
    int res = 0;
    while(p->next != NULL)
    {
        p = p->next;
        res++;
    }
    return res;
}

list_nums listadd(list_nums head1,list_nums head2)
{
    list_nums bg1,bg2,bg3,c,p;
    bg3 = (list_nums)malloc(sizeof(nums));
    bg3->next = NULL;
    p = bg3;
    bg1 = head1->next;
    bg2 = head2->next;

    while(bg1 != NULL && bg2 != NULL)
    {
        c = (list_nums)malloc(sizeof(nums));
        if(bg1->power == bg2->power)
        {
            c->item = bg1->item + bg2->item;
            c->power = bg1->power;
            bg1 = bg1->next;
            bg2 = bg2->next;
        }
        else if(bg1->power < bg2->power)
        {
            c->item = bg1->item;
            c->power = bg1->power;
            bg1 = bg1->next;
        }
        else
        {
            c->item = bg2->item;
            c->power = bg2->power;
            bg2 = bg2->next;
        }
        c->next = NULL;
        p->next = c;
        p = c;
    }

    if(bg1 != NULL)
    {
        while(bg1 != NULL)
        {
            c = (list_nums)malloc(sizeof(nums));
            c->item = bg1->item;
            c->power = bg1->power;
            c->next = NULL;
            p->next = c;
            p = c;
            bg1 = bg1->next;
        }
    }
    else
    {
        while(bg2 != NULL)
        {
            c = (list_nums)malloc(sizeof(nums));
            c->item = bg2->item;
            c->power = bg2->power;
            c->next = NULL;
            p->next = c;
            p = c;
            bg2 = bg2->next;
        }
    }
    return bg3;
}


list_nums listreduce(list_nums head1,list_nums head2)
{
    list_nums bg1,bg2,bg3,c;
    bg1 = head1;
    bg2 = head2;
    c = bg2;
    while(c->next != NULL)     //对里边的一个加数取相反数
    {
        c = c->next;
        c->item *= -1;
    }
    bg3 = listadd(bg1,bg2);
    c = bg2;
    while(c->next != NULL)
    {
        c = c->next;
        c->item *= -1;
    }
    return bg3;
}



int main(void)
{
    int i;
    list_nums head1,head2,res;
    res = NULL;

    head1 = list_init(head1);
    std::cout << "第一个多项式为:" << std::endl;
    printlist(head1);
    std::cout << std::endl;

    head2 = list_init(head2);
    std::cout << "第二个多项式为:" << std::endl;
    printlist(head2);
    std::cout << std::endl;

    std::cout << "请选择你的功能 1(相加) 2(相减)" << std::endl;
    std::cin >> i;
    if(i == 1)
    {
        res = listadd(head1,head2);
        printlist(res);
    }
    else if(i == 2)
    {
        res = listreduce(head1,head2);
        printlist(res);
    }
    else
    {
        std::cout << "md好好输入^-^" << std::endl;
    }
    return 0;
}