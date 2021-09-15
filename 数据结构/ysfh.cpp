#include<cctype>
#include<iostream>
#include<vector>

typedef struct person
{
    int id;
    int passwd;
    struct person *next;
    struct person *perror;
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
    q->perror = NULL;
    q->next = NULL;

    for(int i = 2 ;i <= n; i++)
    {
        p = (per*)malloc(sizeof(per));
        printf("请输入%d号的passwd\n",i);
        std::cin >> p->passwd;
        p->id = i;
        p->perror = q;
        q->next = p;
        q = p;
    }
    head->perror = q;
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
                p = p->next;
            }
            p->perror->next = p->next;
            p->next->perror = p->perror;
            l = p->passwd;
            q = p;
            if(p->next == p)
            {
                printf("出局的人为%d号\n",p->id);
                free(p);
                break;
            }
            printf("出局的人为%d号\n",q->id);
            p = p->next;
            free(q);
        }
    }
}

void list_delet2(list_per head,int nums)
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
                p = p->perror;
            }
            p->perror->next = p->next;
            p->next->perror = p->perror;
            l = p->passwd;
            q = p;
            if(p->perror == p)
            {
                printf("出局的人为%d号\n",p->id);
                free(p);
                break;
            }
            printf("出局的人为%d号\n",q->id);
            p = p->perror;
            free(q);
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
    int nums,n,i;
    std::cout << "请输入成员人数" << std::endl;
    std::cin >> nums;
    head = list_init(head,nums);
    list_forlist(head);
    std::cout << "请输入循环的号" << std::endl;
    std::cin >> n;

    std::cout << "1.顺时针 2.逆时针" << std::endl;
    std::cin >> i;
    if(i == 1)
    list_delet(head,n);
    else
    list_delet2(head,n);
    return 0;
}