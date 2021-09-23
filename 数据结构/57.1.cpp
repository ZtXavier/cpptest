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
    int num = 2;
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


list_info My_reverse(list_info head)
{
    list_info p,q;
    p = head->next;
    head->next = NULL;
    while(p != NULL)     //头插法
    {
        q = p;
        p = p->next;
        q->next = head->next;     //给head进行头插
        head->next = q;
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

int main(void)
{
    list_info head;
    head = list_init(head);
    list_print(head);
    head = My_reverse(head);
    list_print(head);
    return 0;
}