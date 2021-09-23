#include<iostream>


typedef struct info
{
    int data;
    struct info *next;
}*list_info,info;

list_info list_init(list_info head)
{
    head = (list_info)malloc(sizeof(info));
    head->next = NULL;
    list_info p,q;
    q = head;
    int num = 10;
    std::cout << "默认长度为10" << std::endl;
    for(int i = 0;i < num;i++)
    {
        p = (list_info)malloc(sizeof(info));
        std::cout << "请输入数据" <<std::endl;
        std::cin >> p->data;
        q->next = p;
        p->next = NULL;
        q = p;
    }
    return head;
}


void list_print(list_info head)
{
    list_info p;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}


list_info My_delete(list_info head,int x)
{
    list_info p,q;
    p = head;
    while(p->next != NULL)
    {
        if(p->next->data == x)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        p = p->next;
    }
    return head;
}

int main(void)
{
    list_info head;
    head = list_init(head);
    list_print(head);
    int x;
    std::cout << "请输入你要删除的数" << std::endl;
    std::cin >> x;
    head = My_delete(head,x);
    list_print(head);
    return 0;
}