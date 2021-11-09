#include<iostream>
#include<new>

typedef struct List
{
    int data;                   //数据域
    struct List *next;          //指针域
}ListNode;

class listqueue
{
public:
    listqueue(ListNode *head);
    void push(ListNode *head,int data);
    void pop(ListNode *head);
    void print(ListNode *head);
private:
    ListNode *rear;
};

listqueue::listqueue(ListNode *head)
{
    head->data = -1;
    head->next = head;
    rear = head;
}

void listqueue::push(ListNode *head,int data)
{
    ListNode *q = new ListNode[sizeof(ListNode)] ;
    if(q == NULL)
    {
        std::cout << "申请结点失败" << std::endl;
        return ;
    }
    rear->next = q;
    q->data = data;
    q->next = head;
    rear = q;
}

void listqueue::pop(ListNode *head)
{
    if(head->next == head)
    {
        std::cout << "队内无元素" << std::endl;
        return ;
    }
    ListNode *q = head->next;
    head->next = q->next;
    std::cout << "出队元素为" << q->data << std::endl;
    if(q->next == head)        //此处需要判断是否为最后一个元素
    {
        rear = head;
    }
    delete [] q;
    q = NULL;
}

void listqueue::print(ListNode *head)
{
    ListNode *q = head->next;
    if(q == head)
    {
        std::cout << "当前无元素" << std::endl;
        return;
    }
    while(q != head)
    {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = new ListNode[sizeof(ListNode)];
    listqueue list(head);
    list.push(head,12);
    list.print(head);
    for (int i = 1;i < 10;i++)
    {
        list.push(head,i);
    }
    list.print(head);
    list.pop(head);
    list.print(head);
    return 0;
}

