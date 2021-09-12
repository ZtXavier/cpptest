#include<cctype>
#include<iostream>
#include<vector>

typedef struct person
{
    int id;
    int passwd;
    struct person *next;
}per,*list_per;




list_per list_init(list_per head,int n)
{
    list_per p,q;
    q = p = head;
    head = (per*)malloc(sizeof(per));
    q = head;
    printf("请输入1号的passwd\n");
    std::cin >> q->passwd;
    q->id = 1;

    for(int i = 2 ;i <= n; i++)
    {
        p = (per*)malloc(sizeof(per));
        printf("请输入%d号的passwd\n",i);
        std::cin >> p->passwd;
        p->id = i;
        q->next = p;
        q = p;
    }
    q->next = head;
    return head;
}

void list_delet(list_per head,int nums)
{
    list_per q,p;
    int l = nums;
    q = p =head;
    if(!head)
    std::cout << "无人在该圈内" << std::endl;
    else
    {
        while(1)
        {
            for(int i = 1;i < l;i++)
            {
                if(i == l - 1)
                q = p;

                p = p->next;
            }
            q->next = p->next;
            l = p->passwd;
            if(p->next == p)
            {
                printf("出局的人为%d号\n",p->id);
                free(p);
                break;
            }
            printf("出局的人为%d号\n",p->id);
            free(p);
            p = q->next;
        }
    }
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
        printf("\t[id:%d] [passwd:%d]\n",p->id,p->passwd);
        while(p->next != head)
        {
            p = p ->next;
            printf("\t[id:%d] [passwd:%d]\n",p->id,p->passwd);
        }
    }
}



int main(void)
{
    list_per head = NULL;
    int nums,n;
    std::cout << "请输入成员人数" << std::endl;
    std::cin >> nums;
    head = list_init(head,nums);
    list_forlist(head);
    std::cout << "请输入循环的号" << std::endl;
    std::cin >> n;
    list_delet(head,n);
    return 0;
}