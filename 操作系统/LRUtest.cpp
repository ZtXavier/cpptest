#include<iostream>
#include<map>
#include<list>


struct ListNode
{
    int m_k;
    int m_v;
    ListNode *pre;
    ListNode *next;

    ListNode(int key,int value)
    {
        m_k = key;
        m_v = value;
        pre = NULL;
        next = NULL;
    }
};

class LRUcache
{
    public:
        LRUcache(int size);
        ~LRUcache();

        void Remove(ListNode *node);
        void Sethead(ListNode *node);
        void Set(int key,int value);
        void print_v();
        int Get(int key);
        int getSize() { return mp.size(); }

    private:
        int m_Capacity;
        ListNode *head;
        ListNode *tail;
        std::map<int,ListNode*> mp;
};  

LRUcache::LRUcache(int size)
{
    m_Capacity = size;
    head = NULL;
    tail = NULL;
}

LRUcache::~LRUcache()
{
    std::map<int,ListNode*>::iterator it = mp.begin();
    while(mp.end() != it)
    {
        delete it->second;
        it->second = NULL;
        mp.erase(it++);
    }
    delete head;
    delete tail;
    head = tail = NULL;
}


void LRUcache::Remove(ListNode *node)
{
    if(node->pre == NULL)
    {
        head = node->next;
        head->pre = NULL;
    }
    else if(node->next == NULL)
    {
        tail = node->pre;
        tail->next = NULL;
    }
    else
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
}

void LRUcache::Sethead(ListNode *node)
{
    node->next = head;
    node->pre = NULL;

    if(head == NULL)
    {
        head = node;
    }
    else
    {
        head->pre = node;
        head = node;
    }
    if(tail == NULL)
    {
        tail =  head;
    }
}

void LRUcache::Set(int key,int value)
{
    std::map<int,ListNode*>:: iterator it = mp.find(key);
    // 如果在缓冲区中，更新节点到最新的头节点
    if(it  != mp.end())
    {
        ListNode *node = it->second;
        node->m_v = value;
        Remove(node);
        Sethead(node); 
    }
    // 如果没有找到，将tail所指的最旧的数据删除，更新新的节点
    else
    {
        ListNode *NewNode = new ListNode(key,value);
        if(mp.size() >= m_Capacity)
        {
            std::map<int,ListNode*>::iterator it = mp.find(tail->m_k);
            Remove(tail);
            delete it->second;
            mp.erase(it);
        }
        Sethead(NewNode);
        mp[key] = NewNode;
    }
}

int LRUcache::Get(int key)
{
    std::map<int,ListNode*>::iterator it = mp.find(key);
    if(it != mp.end())
    {
        ListNode *node = it->second;
        Remove(node);
        Sethead(node);
        std::cout << "success! " << std::endl;
        return node->m_v; 
    }
    else
    {
        std::cout << "命中失败，没有找到数据"  << std::endl;
        return -1;
    }
}

void LRUcache::print_v()
{   
    int size = mp.size();
    if(size == 0)
    {
        std::cout << "没有数据" << std::endl;
    }
    else
    {
        
        std::cout << "------------------------------------" << std::endl;
        for(ListNode *node = head;node;node = node->next )
        {
            std::cout << node->m_k << " -> " << node->m_v << std::endl;
        }
        std::cout << "------------------------------------" << std::endl;
    }

}




int main()
{
    LRUcache *lrucache = new LRUcache(3);
    lrucache->Set(1,2);
    lrucache->Set(2,3);
    lrucache->Set(3,7);
    lrucache->print_v();
    lrucache->Set(1,2);
    lrucache->print_v();
    std::cout << lrucache->Get(3) << std::endl; 
    std::cout << lrucache->Get(4) << std::endl;
    lrucache->print_v();
    lrucache->Set(1,5);
    lrucache->print_v();
    return 0;
}