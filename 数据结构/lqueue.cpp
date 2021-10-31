#include<iostream>

typedef struct info
{
    int num;
    struct info *next;
}in,*list;

list init(list head,int len)
{
    list p,q;
    head = new(in);
    q = head;
    head->next = NULL;
    for(int i = 0;i < len;i++)
    {
        p = new(in);
        q->next = p;
        p->num = i;
        q = p;
        p->next = NULL;
    }
    p->next = head->next;
    return head;
}

list list_insert(list head,list front,list rail)
{
    
    front = head->next;
    return front;
}


int main()
{
    return 0;
}