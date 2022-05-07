#include"MemManager.hpp"


MemManager::MemManager(int num,long address,long length,int state)
{
    head = new Node(num,address,length,state);
    nodenums_ = 1;
}

MemManager::MemManager(long length):MemManager(0,0,30,1)
{
    if(length <= 30)
    {
        std::cout << "分配的内存不足"  << std::endl;
        exit(0);
    }
    maxLen_ = length;
    head->next_ = new Node(1,30,maxLen_  - 30,0,head,NULL);
}

void MemManager::show()
{
    int nums = 0;
    Node* p = head;
    printf("\t\t>主存空间分配状态<\n");
    printf("分区序号\t起始地址\t分区大小\t分区状态\n");
    while(p)
    {
        printf("%d\t\t%ld\t\t%ldKB\t\t",p->ElemTable.num_,p->ElemTable.address_,p->ElemTable.length_);
        if(p->ElemTable.state_ == 0)
            printf("未分配\n");
        else
            printf("已分配\n");
        p = p->next_;
    }
}

// 最佳适配
int MemManager::bestFit(long Memsize)
{
    Node *p = head->next_;
    Node*reac = p;
    //该循环作用是先从内存中找到一块最大的空闲内存
    while(p)
    {
        if(p->ElemTable.state_ == 0)
        {
            if(p->ElemTable.length_ >= reac->ElemTable.length_)
            {
                reac = p;
            }
        }
        p = p->next_;
    }
    // 在在最大的基础上寻找更加合适的内存
    p = head;
    while(p)
    {
        if(p->ElemTable.state_ == 0)
        {
            if(p->ElemTable.length_ > Memsize && p->ElemTable.length_ <= reac->ElemTable.length_)
            {
                reac = p;
            }
        }
        p = p->next_;
    }
    return allocateMemory(reac,Memsize);
}

// 首次适配
int MemManager::firstFit(long Memsize)
{   
    Node* reac = head->next_;
    while(reac)
    {
        if(reac->ElemTable.state_ == 0)
        {
            if(reac->ElemTable.length_ >= Memsize)
            {
                break;
            }
        }
        reac = reac->next_;
    }
    return allocateMemory(reac,Memsize);
}

// 最差适配
int MemManager::maxFit(long Memsize)
{
    Node* p = head->next_;
    Node* reac = p;
     while(p)
    {
        if(p->ElemTable.state_ == 0)
        {
            if(p->ElemTable.length_ >= reac->ElemTable.length_)
            {
                reac = p;
            }
        }
        p = p->next_;
    }
    return allocateMemory(reac,Memsize);
}

int MemManager::allocateMemory(Node* reac,long Memsize)
{
    if(reac != NULL && reac->ElemTable.length_ < Memsize)
    {
        printf("内存不足以分配!!!\n");
        exit(0);
    }
    ++nodenums_;
    if(reac->ElemTable.length_ == Memsize)
    {
        reac->ElemTable.state_ = 1;
        reac->ElemTable.num_ = nodenums_;
        return nodenums_;
    }
    long nodeAddr = reac->ElemTable.address_;
    Node* newNode = new Node(nodenums_,nodeAddr,Memsize,1,reac->prior_,reac);
    reac->ElemTable.address_ += Memsize;
    reac->ElemTable.length_ -= Memsize;
    reac->prior_->next_ = newNode;
    reac->prior_ = newNode;
    return nodenums_;
}


void MemManager::freeMemory(int Memofnum)
{
    if(Memofnum < 0 || Memofnum > nodenums_)
    {
        printf("can not free this memory!!!\n");
        exit(1);
    }

    Node* p = head;
    while(p)
    {
        if(p->ElemTable.num_ == Memofnum)
        {
            p->ElemTable.state_ = 0;
            break;
        }
        p = p->next_;
    }

    // 需要考虑向上或向下合并
    //四种情况：向上，向下，上下都要合并，没有邻接的空闲内存
    if(p->next_ && p->next_->ElemTable.state_ == 0)
    {
        p = p->next_;
    }
    // 从一边出发来进行合并，这种思想很好的将两边的空闲内存都合并
    while(p->prior_ && p->prior_->ElemTable.state_ == 0)
    {
        p->prior_->ElemTable.length_ += p->ElemTable.length_;
        p->prior_->next_ = p->next_;
        if(p->next_ != NULL)
        {
            p->next_->prior_ = p->prior_;
        }
        Node * fr = p;
        p = p->prior_;
        delete fr;
    }
}


int MemManager::requestMemory(long Memsize)
{
    return bestFit(Memsize);
}
